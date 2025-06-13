#include <stdio.h>
#include <math.h>
typedef struct {
    int shapeType; // 1 for cirlce 2 for rectangle 3 for triangle.
    union {
        float radius;
        struct {
            float length;
            float width;
        };
        struct {
            float height;
            float base;
        };
    } Dimentions;
} Shape;

int main(){
    int type;
    scanf("%d", &type);

    if (type == 1){
        float radius;
        scanf("%f", &radius);
        if (radius >= 0){
            Shape circle;
            circle.shapeType = 1;
            circle.Dimentions.radius = radius;
            printf("%.2f\n", (M_PI * circle.Dimentions.radius * circle.Dimentions.radius));
        }else{
            printf("-999\n");
        }
    }else if (type == 2){
        float length, breadth;
        scanf("%f %f", &length, &breadth);
        if (length >= 0 && breadth >= 0){
            Shape rect;
            rect.shapeType = 2;
            rect.Dimentions.width = breadth;
            rect.Dimentions.length = length;
            printf("%.2f\n", rect.Dimentions.length * rect.Dimentions.width);
        }else{
            printf("-999\n");
        }
    }else{
        float base, height;
        scanf("%f %f", &base, &height);
        if (base >= 0 && height >= 0){
            Shape tri;
            tri.shapeType = 3;
            tri.Dimentions.base = base;
            tri.Dimentions.length = height;

            printf("%.2f\n", (0.5 * tri.Dimentions.height * tri.Dimentions.base));
        }else{
            printf("-999\n");
        }
    }
    return 0;
}