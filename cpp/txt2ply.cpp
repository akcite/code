/////////////////////////////////////////////////////////////////////////////////////
// txt2ply

#include <stdio.h>
#include <vector>
#include <string>

struct PTS {
  PTS(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {};
  float x;
  float y;
  float z;
};

int main(int argc, char** arg) {
  std::vector<PTS> vertex;

  FILE* fp = fopen(arg[1], "r");

  float x, y, z;
  while(fscanf(fp, "%f %f %f\n", &x, &y, &z) != EOF) {
    PTS pts(x, y, z);
    vertex.push_back(pts);
  }
  fclose(fp);

  std::string word(arg[1]);

  size_t found = word.find_last_of(".");
  word = word.substr(0, found);

  char file_name[128];
  sprintf(file_name, "%s.ply", word.c_str());

  fp = fopen(file_name, "w");

  fprintf(fp, "ply\n");
  fprintf(fp, "format binary_little_endian 1.0\n");
  fprintf(fp, "element vertex %d\n", (int) (vertex.size()));
  fprintf(fp, "property float x\n");
  fprintf(fp, "property float y\n");
  fprintf(fp, "property float z\n");
  fprintf(fp, "end_header\n");

  for (int x = 0; x < (int) vertex.size(); ++x) {
    PTS pts = vertex[x];
    fwrite(&pts.x, sizeof(float), 1, fp);
    fwrite(&pts.y, sizeof(float), 1, fp);
    fwrite(&pts.z, sizeof(float), 1, fp);
  }

  fclose(fp);
  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
