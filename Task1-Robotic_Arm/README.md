# task1-robot-arm

## Team Members

| Names                                   | Sec   | B.N |
|--------------------------------------   |:----- |:----|                                                                           
| Yara Hossam El-Din Mostafa              | 2     | 48  |
| Esraa Osama                             | 1     | 10  |
| Habiba Mohamed Hanafy                   | 1     | 25  |
| Maryam Mahmoud Mohamed Elsayed          | 2     | 29  |
 



## Code Describtion

* Drawing The first segment of the finger 
1. `glTranslate` produces a translation by +1 in the x-direction to move the centre of the finger to pass the edge of the elbow segment 

		glTranslatef(1.0, -0.225, 0.0); 		
2. `glRotate` produces a rotation in the z direction 

	  ```
		glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0); 	
3. Here the center of the finger is at the half of its edge

    ```
    glTranslatef(0.15, 0.0, 0.0); 
4. Push CM in the stack
    ```
    glPushMatrix(); 
5. Here we will Create a square of length one side and the center is the origin , CM * Cube 
    ```
    glScalef(0.3, 0.15, 0.15); 
    glutWireCube(1); 
    glPopMatrix();
6. That is the result

   ![fisrt segment of the finger](https://i.imgur.com/TPZ5W3Q.png)
* Drawing The second segment of the finger

###### Here the second segment will be created at the same coordinates so we need to shift it in the direction of x axis
    
    glTranslatef(0.15, 0.0, 0.0); 
    glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.15, 0.15);
    glutWireCube(1);
    glPopMatrix();
    
 ![The second segment of the finger](https://i.imgur.com/OwG8Qpq.png)

* The other fingers works with the same idea and here is the final result

 ![The Final Result](https://i.imgur.com/aeUTCYs.png)
 
 ---
 ## The Issues we faced
 
| The issues                                    | Solutions                                                                       |
|---------------------------------------------  |:--------------------------------------------------------------------------------|                                                                           
| No Fixed Axes in the interface              | We fixed a view and drawed fixed axis to control the positioning of the segments|
| The fingers not rotating with the same degree | We searched on google the understand how `glRotate` works                       |
| After working on the position of the fingers and beginning to work in rotation part, we find that every finger is dependant on the previous fingers | We understood the role of  `push` and `pop` functions and the concept of current matrix |
 
 
 


