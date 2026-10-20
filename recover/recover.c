#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  const int BLOCK_SIZE_BYTES = 512;
  uint8_t buffer[BLOCK_SIZE_BYTES];
  int file_count = 0;
  char padding[3];
  char file_name[sizeof(int) * 3 + sizeof(".jpg") + sizeof(padding)];
  //   printf("%li\n", sizeof(file_name));
  if (argc != 2) {
    printf("Usage: ./recover FILE\n");
    return 1;
  }
  FILE *src = fopen(argv[1], "r");
  if (src == NULL) {
    printf("Can't open source file.\n");
    return 1;
  }
  FILE *img = NULL;
  while (fread(buffer, 1, BLOCK_SIZE_BYTES, src) == BLOCK_SIZE_BYTES) {
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
        (buffer[3] >= 0xe0 && buffer[3] <= 0xef)) {
      if (file_count != 0) {
        fclose(img);
      }
      if (file_count < 10) {
        padding[0] = '0';
        padding[1] = '0';
        padding[2] = '\0';

      } else {
        padding[1] = '\0';
      }
      sprintf(file_name, "%s%i.jpg", padding, file_count);
      img = fopen(file_name, "w");
      file_count++;
    }
    if (img == NULL) {
      continue;
    }
    fwrite(buffer, 1, BLOCK_SIZE_BYTES, img);
  }
  if (img != NULL) {
    fclose(img);
  }
  fclose(src);
}
// open the new file and close
