#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the  diamension of the window
#define HEIGHT 1000
#define WIDTH 1000
#define ITER 100000000L

// define the vertex of the triangle,say on the cartesian plane

// makes points on the plane to make  a  canvas:
//(x1, y1) => (750, 50)
#define V1_X (WIDTH / 2)
#define V1_Y 50

//(x2, y2) => (50, 750)
#define V2_X 50
#define V2_Y (HEIGHT - 50)

//(x3, y3) => (750, 750)
#define V3_X (WIDTH - 50)
#define V3_Y (HEIGHT - 50)

// draw pixel on the image buffer
// x & y are the positions in the  plane
void put_pixel(unsigned char *image_rep, int x, int y, unsigned char r,
               unsigned char b, unsigned char g) {

  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
    int index = (y * WIDTH + x) * 3; // make pixel with 3 components (rgb)

    image_rep[index] = r;
    image_rep[index + 1] = g;
    image_rep[index + 2] = b;
  }
}

void write_ppm(char *filename, unsigned char *image_rep) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {

    perror("WRITE failed\n");
    free(image_rep);
    exit(1);
  }
  fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

  fwrite(image_rep, 1, WIDTH * HEIGHT * 3, fp);

  fclose(fp);
  free(image_rep);

  printf("sierpenski triangle written to spk.ppm\n");
}

int main() {
  unsigned char *image_rep = malloc(WIDTH * HEIGHT * 3); // 3 color components
  if (!image_rep) {
    perror("allocation\n");
    return 1;
  }
  for (int i = 0; i < WIDTH * HEIGHT * 3; ++i) {
    // set the bg to be black
    image_rep[i] = 0;
  }
  srand((unsigned int)time(NULL));

  // make 3 rows and 2 columns
  int vertices[3][2] = {
      {V1_X, V1_Y},
      {V2_X, V2_Y},
      {V3_X, V3_Y},
  };
  double current_x = vertices[0][0];
  double current_y = vertices[0][1];

  for (long i = 0; i < ITER; ++i) {
    int chosen_v_index = rand() % 3;
    int target_x = vertices[chosen_v_index][0];
    int target_y = vertices[chosen_v_index][1];

    // calculate the current positions
    current_x = (current_x + target_x) / 2;
    current_y = (current_y + target_y) / 2;

    // rgb (235, 56,56) for red bg  to colour the pixels
    put_pixel(image_rep, current_x, current_y, 235, 56, 56);
  }
  // remove the previous file before creating a new one
  remove("spk.ppm");

  // write file in ppm format
  write_ppm("spk.ppm", image_rep);

  return 0;
}

