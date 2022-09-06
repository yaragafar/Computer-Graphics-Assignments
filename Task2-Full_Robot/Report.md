# task2-full-robot-graphica
task2-full-robot-graphica created by GitHub Classroom
# Full Robot Assignment

## Code Describtion

### For the camera and projection part: 
1. as the vertical direction of the camera is parallel to the Up vector, we need to rotate each point around the eye vector using the rotation matrix through the function `rotatePoint`
 		
2. then, we computed the rotation axis using cross product as follows:

```
void crossProduct(double a[], double b[], double c[])
{
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
}
```
3. Here we normalize the rotation vector to a unit vector as follows:
```
void normalize(double a[])
{
    double norm;
    norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
    norm = sqrt(norm);
    a[0] /= norm;
    a[1] /= norm;
    a[2] /= norm;
}
```
* To display, we first clear the color buffer using `glClear(GL_COLOR_BUFFER_BIT);` and push the current matrix into the stack `
    
* We create and locate the camera by the eye vector which specifies the location of the camera, the look vector where the camera look at the center and the Up vector that specifies the direction of the camera `gluLookAt(eye[0], eye[1], eye[2], look[0], look[1], look[2], up[0], up[1], up[2]);` 
   
* Then we clear both color and depth buffer `glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);` and display the color we want.

### For the body:
* it is centered at (1.2, 3.2, 0.4), translated to the origin `glTranslatef(0.6, 0.0, 0.0);`, rotated `glRotatef((GLfloat)body, 0.0, 0.0, 1.0);` and then translated back `glTranslatef(-0.6, 0.0, 0.0);`
###### The same thing is applied to the remaining segments of the robot 

* for controlling with the keyboard:
's' is for controlling the right shoulder movement, 'h' is for controlling left shoulder movement, 'e' for controlling right elbow motion, 'l' for controlling left elbow motion, 'f' is for the other left elbow and 'g' is for the other right elbow.
*The letters 'i', 'a', 'c', 'p', 'b', 'd' are for the left and right hip rotations.
'k' is for the right knee rotation.
'n' is for left knee rotation.
'z' for controlling znear.
'w' and 'x' for controlling the scene view of the camera.
   
 ![The Final Result](https://i.imgur.com/VyYojUE.png)
