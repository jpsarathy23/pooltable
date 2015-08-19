#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
//BORED? Go Ahead
//Else, Goto NOT_BORED section. Sorry Can't help it. I AM!!
float X1 = 0.0, Y1 = 0.0, X2 = 284.0, Y2 = 0.0, X3 = 284.0, Y3 = 142.0, X4 = 0.0, Y4 = 142.0;    
float intersect_x(float x1, float x2, float m, float n) {
    return ((m * x2 + n * x1) / (m + n));
}
float intersect_y(float y1, float y2, float m, float n) {
    return ((m * y2 + n * y1) / (m + n));
}
float slope(float x1, float y1, float x2, float y2) {
    return (y2-y1)/(x2-x1);
}
float dist(float x1, float y1, float x2, float y2) {
    return pow(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0), 0.5);
}
float end_x(float x1, float y1, float m) {
    //cout << "end_x " << x1 << " " << y1 << " " << m << endl;
    // HEAVILY RELIED ON RECTANGLE SHAPE OF POOL
    float c = y1 - m * x1;
    if (x1 == X1) { //LEFT X = X1
        float max_slope = slope(x1, y1, X3, Y3); // theta +ve
        float min_slope = slope(x1, y1, X2, Y2); // alpha -ve
        if (m == max_slope) {
            return X3;
        } else if (m == min_slope) {
            return X2;
        } else if (m > max_slope) { // goes to TOP Y = Y3 // theta to pi/2
            return ((Y3-c)/m); 
        } else if(m > min_slope) { // goes to RIGHT X = X2 // theta to alpha 
            return X2; 
        } else { // m < min_slope // goes to BOTTOM Y = Y1 // alpha to -pi/2
            return ((Y1-c)/m); 
        }
    }  
    if (x1 == X2) { //RIGHT X = X2
        float max_slope = slope(x1, y1, X1, Y1); // theta +ve
        float min_slope = slope(x1, y1, X4, Y4); // alpha -ve
        if (m == max_slope) {
            return X1;
        } else if (m == min_slope) {
            return X4;
        } else if (m > max_slope) { // goes to BOTTOM Y = Y1 // theta to pi/2
            return ((Y1-c)/m); 
        } else if(m > min_slope) { // goes to LEFT X = X1 // alpha to -pi/2 
            return X1; 
        } else { // m < min_slope // goes to TOP Y = Y3 // theta to alpha 
            return ((Y3-c)/m); 
        }
    }  
    if (y1 == Y3) { //TOP Y = Y3
        float max_slope = slope(x1, y1, X1, Y1); // theta +ve
        float min_slope = slope(x1, y1, X2, Y2); // alpha -ve
        if (m == max_slope) {
            return X1;
        } else if (m == min_slope) {
            return X2;
        } else if (m > max_slope || m < min_slope) { // goes to BOTTOM Y = Y1 // theta to pi/2 && alpha to -pi/2
            return ((Y1-c)/m); 
        } else if(m < 0) { // goes to RIGHT X = X2 // alpha to 0
            return X2; 
        } else { // m > 0 // goes to LEFT X = X1 // theta to 0
            return X1; 
        }
    }  
    if (y1 == Y1) { //BOTTOm Y = Y1
        float max_slope = slope(x1, y1, X3, Y3); // theta +ve
        float min_slope = slope(x1, y1, X4, Y4); // alpha -ve
        if (m == max_slope) {
            return X3;
        } else if (m == min_slope) {
            return X4;
        } else if (m > max_slope || m < min_slope) { // goes to TOP Y = Y3 // theta to pi/2 && alpha to -pi/2
            return ((Y3-c)/m); 
        } else if(m > 0) { // goes to RIGHT X = X2 // alpha to 0
            return X2; 
        } else { // m > 0 // goes to LEFT X = X1 // theta to 0
            return X1; 
        }
    }  
}
float end_y(float x1, float y1, float m) {
    //cout << "end_y " << x1 << " " << y1 << " " << m << endl;
    float c = y1 - m * x1;
    if (x1 == X1) { //LEFT X = X1
        float max_slope = slope(x1, y1, X3, Y3); // theta +ve
        float min_slope = slope(x1, y1, X2, Y2); // alpha -ve
        if (m == max_slope) {
            return Y3;
        } else if (m == min_slope) {
            return Y2;
        } else if (m > max_slope) { // goes to TOP Y = Y3 // theta to pi/2
            return Y3; 
        } else if(m > min_slope) { // goes to RIGHT X = X2 // theta to alpha 
            return (m * X2 + c); 
        } else { // m < min_slope // goes to BOTTOM Y = Y1 // alpha to -pi/2
            return Y1; 
        }
    }  
    if (x1 == X2) { //RIGHT X = X2
        float max_slope = slope(x1, y1, X1, Y1); // theta +ve
        float min_slope = slope(x1, y1, X4, Y4); // alpha -ve
        if (m == max_slope) {
            return Y1;
        } else if (m == min_slope) {
            return Y4;
        } else if (m > max_slope) { // goes to BOTTOM Y = Y1 // theta to pi/2
            return Y1; 
        } else if(m > min_slope) { // goes to LEFT X = X1 // alpha to -pi/2 
            return (m * X1 + c); 
        } else { // m < min_slope // goes to TOP Y = Y3 // theta to alpha 
            return Y3; 
        }
    }  
    if (y1 == Y3) { //TOP Y = Y3
        float max_slope = slope(x1, y1, X1, Y1); // theta +ve
        float min_slope = slope(x1, y1, X2, Y2); // alpha -ve
        if (m == max_slope) {
            return Y1;
        } else if (m == min_slope) {
            return Y2;
        } else if (m > max_slope || m < min_slope) { // goes to BOTTOM Y = Y1 // theta to pi/2 && alpha to -pi/2
            return Y1; 
        } else if(m < 0) { // goes to RIGHT X = X2 // alpha to 0
            return (m * X2 + c); 
        } else { // m > 0 // goes to LEFT X = X1 // theta to 0
            return (m * X1 + c); 
        }
    }  
    if (y1 == Y1) { //BOTTOm Y = Y1
        float max_slope = slope(x1, y1, X3, Y3); // theta +ve
        float min_slope = slope(x1, y1, X4, Y4); // alpha -ve
        if (m == max_slope) {
            return Y3;
        } else if (m == min_slope) {
            return Y4;
        } else if (m > max_slope || m < min_slope) { // goes to TOP Y = Y3 // theta to pi/2 && alpha to -pi/2
            return Y3; 
        } else if(m > 0) { // goes to RIGHT X = X2 // alpha to 0
            return (m * X2 + c); 
        } else { // m > 0 // goes to LEFT X = X1 // theta to 0
            return (m * X1 + c); 
        }
    }  
}
int main() {
    //COUNTER-CLOCKWISE 
    float start_x, start_y;
    float first_x, first_y;
    float speed;
    float time;
    int retry_limit = 5;
    int i=0;
    while (i++ < retry_limit) {
        printf("Enter initial position x co-ordinate y co-ordinate:\n");
        scanf("%f %f", &start_x, &start_y);
        if ( start_x < X1 || start_x > X2 || start_y < Y1 || start_y > Y3) {
            printf("Uh! Don't Drop the ball! Place it on the Table. Won't you??\n");
        } else {
            break;
        }
        if (i == retry_limit) {
            printf("You Won't! Good Bye!!\n");
        }
    }
    i = 0;
    while (i++ < retry_limit) {
        printf("Enter first hit position on the cushion x co-ordinate y co-ordinate:\n");
        scanf("%f %f", &first_x, &first_y);
        if ( first_x < X1 || first_x > X2 || first_y < Y1 || first_y > Y3) {
            printf("Err! Hit the Ball Nicely!! Not that it flies off the Table :/\n");
        } else if ( first_x != X1 && first_x != X2 && first_y != Y1 && first_y != Y4) {
            printf("Err! Hit the Ball to the cushion!! :( Try Again!\n");
            
        } else {
            break;
        }

        if (i == retry_limit) {
            printf("You are drunk! Good Bye!!\n");
        }
    }
    i=0;
    while (i++ < retry_limit) {
        printf("Enter speed of ball (in cm/s). (Between 0 and 1000 cm/s) :\n");
        scanf("%f", &speed);
        if ( speed == 0.0 || speed > 1000.0) {
            printf("Urr! You either didn't hit the ball or have hit it too fast. Try Again! :|\n");
        } else {
            break;
        }
        if (i == retry_limit) {
            printf("You Can't! Good Bye!!\n");
        }
    }
    printf("Enter travelling time (in seconds):\n"); 
    scanf("%f", &time);
    if (time > 86400.0) {
        printf("INFO : Collisions are elastic. But, please don't burn the CPU just because of that\n");
    }
    //For that soul reading the code, if at all it happens, sorry for the brief inputting logic :D
    //Read from here, if you are NOT_BORED..
    float time_elapsed = 0.0;
    float curr_start_x, curr_start_y, curr_end_x, curr_end_y, curr_dist, curr_slope;
    curr_start_x = start_x, curr_start_y = start_y, curr_end_x = first_x, curr_end_y = first_y;
    curr_slope = slope (curr_start_x, curr_start_y, curr_end_x, curr_end_y);
    curr_dist = dist (curr_start_x, curr_start_y, curr_end_x, curr_end_y);
    float time_reqd = curr_dist/speed;
    float end_X, end_Y;
    if ( time_reqd > time - time_elapsed) { 
        float actual_dist = speed * (time - time_elapsed);
        end_X = intersect_x (curr_start_x, curr_end_x, actual_dist, curr_dist-actual_dist);
        end_Y = intersect_y (curr_start_y, curr_end_y, actual_dist, curr_dist-actual_dist);
    } 
    else {
        time_elapsed += time_reqd;
        curr_start_x = first_x, curr_start_y = first_y;
        if ((first_x == X1 && first_y ==Y1) || (first_x == X2 && first_y ==Y2) || (first_x == X3 && first_y ==Y3) || (first_x == X4 && first_y ==Y4));
        else curr_slope = -1.0 * curr_slope;
        while (time_elapsed < time) {
            //curr_start_x = curr_end_x;
            //curr_start_y = curr_end_y;
            //cout << "curr_start " << curr_start_x << " , " << curr_start_y << endl;
            //cout << "curr_slope " << curr_slope << endl;
            curr_end_x = end_x (curr_start_x, curr_start_y, curr_slope);
            curr_end_y = end_y (curr_start_x, curr_start_y, curr_slope);
            curr_dist = dist (curr_start_x, curr_start_y, curr_end_x, curr_end_y);
            float time_reqd = curr_dist/speed;
            if ( time_reqd > time - time_elapsed) {
                float actual_dist = speed * (time - time_elapsed);
                end_X = intersect_x (curr_start_x, curr_end_x, actual_dist, curr_dist-actual_dist);
                end_Y = intersect_y (curr_start_y, curr_end_y, actual_dist, curr_dist-actual_dist);
                break;
            }
            time_elapsed += time_reqd;
            if ((curr_end_x == X1 && curr_end_y ==Y1) || (curr_end_x == X2 && curr_end_y ==Y2) || (curr_end_x == X3 && curr_end_y ==Y3) || (curr_end_x == X4 && curr_end_y ==Y4));
            else curr_slope = -1.0 * curr_slope;
            curr_start_x = curr_end_x;
            curr_start_y = curr_end_y;
            //cout << "curr_end " << curr_end_x << " , " << curr_end_y << endl;
            //cout << "time_elapsed " << time_elapsed << endl;
        }
    }
    printf("Acha! Your Ball is at %.6f , %.6f\n", end_X, end_Y);
    return 0;
}

