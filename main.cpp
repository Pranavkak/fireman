#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include "agent.h"
#include "env.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>


float x = 1.0f;
float y = 0.0f;
float z = 0.0f;
float delta = 0.1f;

bool isJumping = false;
float jumpSpeed = 0.05f;
float jumpHeight = 1.0f;
float agentRotation = 0.0f;

const int MAX_COINS = 10;
float coinPositions[MAX_COINS][3];
bool coinVisible[MAX_COINS];

bool carVisible = true;

struct Fireball {
    float position[3];
    float velocity[3];
};

std::vector<Fireball> fireballs;


//Fire Animation
void drawFire(float x, float y, float z, float size) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(size, size, size);

    // Draw the fire using triangle fans
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f);  // Red
    glVertex3f(0.0f, 0.0f, 0.0f);

    const int numFlames = 8;
    const float angleStep = 2.0f * M_PI / numFlames;
    const float flameHeight = 1.5f;
    const float flameWidth = 0.5f;

    for (int i = 0; i <= numFlames; i++) {
        float angle = i * angleStep;
        float flameX = flameWidth * cos(angle);
        float flameY = flameHeight * sin(angle * 2.0f) * sin(glutGet(GLUT_ELAPSED_TIME) * 0.001f);

        if (i % 2 == 0) {
            glColor3f(1.0f, 0.5f, 0.0f);  // Orange
        } else {
            glColor3f(1.0f, 1.0f, 0.0f);  // Yellow
        }

        glVertex3f(flameX, flameY, 0.0f);
    }

    glEnd();

    glPopMatrix();
}

//shoot
void drawFireballs() {
    for (const auto& fireball : fireballs) {
        glPushMatrix();
        glTranslatef(fireball.position[0], fireball.position[1], fireball.position[2]);
        glColor3f(1.0f, 0.5f, 0.0f);  // Orange color
        glutSolidSphere(0.2f, 20, 20);
        glPopMatrix();
    }
}

//shoot update
void updateFireballs() {
    for (auto it = fireballs.begin(); it != fireballs.end();) {
        it->position[0] += it->velocity[0];
        it->position[1] += it->velocity[1];
        it->position[2] += it->velocity[2];

        // Check for collision with the car
        float carPosition[3] = {-2.0f, 0.5f, -5.0f};  // Update with the actual car position
        float dx = it->position[0] - carPosition[0];
        float dy = it->position[1] - carPosition[1];
        float dz = it->position[2] - carPosition[2];
        float distance = sqrt(dx * dx + dy * dy + dz * dz);

        if (distance < 1.0f) {  // Adjust the collision threshold as needed
            // Car is hit by the fireball
            // Perform desired action, e.g., make the car disappear
            // For simplicity, let's assume you have a boolean variable 'carVisible' to control the car's visibility
            carVisible = false;
            it = fireballs.erase(it);  // Remove the fireball
            
        } else {
            ++it;
        }
    }
}


void initializeCoins() {
    for (int i = 0; i < MAX_COINS; i++) {
        coinPositions[i][0] = (rand() % 20) - 10.0f;  // Random x position between -10 and 10
        coinPositions[i][1] = 0.5f;  // Height of the coins above the ground
        coinPositions[i][2] = (rand() % 20) - 10.0f;  // Random z position between -10 and 10
        coinVisible[i] = true;
    }
}

void drawCoins() {
    for (int i = 0; i < MAX_COINS; i++) {
        if (coinVisible[i]) {
            glPushMatrix();
            glTranslatef(coinPositions[i][0], coinPositions[i][1], coinPositions[i][2]);
            glColor3f(1.0f, 0.84f, 0.0f);  // Gold color
            glutSolidSphere(0.3f, 20, 20);
            glPopMatrix();
        }
    }
}

void checkCoinCollisions() {
    for (int i = 0; i < MAX_COINS; i++) {
        if (coinVisible[i]) {
            float dx = x - coinPositions[i][0];
            float dy = (y + 0.8f) - coinPositions[i][1];
            float dz = z - coinPositions[i][2];
            float distance = sqrt(dx * dx + dy * dy + dz * dz);

            if (distance < 0.5f) {  // Adjust the collision threshold as needed
                coinVisible[i] = false;
            }
        }
    }
}


void display() {
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set the camera position and orientation
    gluLookAt(0.0f, 2.0f, 6.0f,   // Camera position
              0.0f, 0.0f, 0.0f,   // Look-at point
              0.0f, 1.0f, 0.0f);  // Up vector

    
    if(!carVisible){
        drawFire(-2.0f,0.3f,-5.0f,1.0f);
    }
        
    drawGround();
    drawCoins();
    drawFireballs();

    glPushMatrix();
    glTranslatef(x, y + 0.6f, z);  
    glRotatef(agentRotation, 0.0f, 1.0f, 0.0f);
    agent();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.3f, -5.0f);  
    glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
    tree();
    glPopMatrix();

    if(carVisible){
        glPushMatrix();
    glTranslatef(-2.0f, 0.3f, -5.0f);  
    glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
    car();
    glPopMatrix();
    }
    
    glPushMatrix();
    glTranslatef(2.0f, 0.3f, -5.0f);  
    glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
    home();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
}

void timer(int value) {
    updateFireballs();
    checkCoinCollisions();
    if (isJumping) {
        y += jumpSpeed;
        if (y >= jumpHeight) {
            isJumping = false;
        }
    } else {
        if (y > 0.0f) {
            y -= jumpSpeed;
            if (y < 0.0f) {
                y = 0.0f;
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void keyboard(unsigned char key, int unused0, int unused1) {
    switch (key) {
        case 'w':
            z -= delta;
            break;
        case 'a':
            x -= delta;
            break;
        case 's':
            z += delta;
            break;
        case 'd':
            x += delta;
            break;
        case ' ':
            if (!isJumping) {
                isJumping = true;
            }
            break;
        case 'k':
            agentRotation -= 5.0f;  // Rotate left by 5 degrees
            break;
        case 'l':
            agentRotation += 5.0f;  // Rotate right by 5 degrees
            break;
        case 'f':  // Press 'f' to shoot fireball
        {
            Fireball fireball;
            fireball.position[0] = x;
            fireball.position[1] = y + 0.8f;
            fireball.position[2] = z;
            float speed = 0.2f;  // Adjust the speed as needed
            float angle = agentRotation * M_PI / 180.0f;  // Negate the angle to align with the front side
            fireball.velocity[0] = speed * sin(angle);
            fireball.velocity[1] = 0.0f;
            fireball.velocity[2] = speed * cos(angle);  // Remove the negative sign to align with the front side
            fireballs.push_back(fireball);
        }
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("Cube");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0); // Start the timer immediately
    glutKeyboardFunc(keyboard);
    drawGround();
    initializeCoins();
    glutMainLoop();
    return 0;
}