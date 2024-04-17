void home() {
    // Base
    glColor3f(0.8f, 0.8f, 0.8f);  // Light gray
    glPushMatrix();
    glScalef(1.5f, 1.0f, 1.5f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Roof
    glColor3f(0.6f, 0.2f, 0.2f);  // Dark red
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glRotatef(45.0f, -1.0f, 0.0f, 0.0f);
    glScalef(1.7f, 1.7f, 1.7f);
    glutSolidCone(0.5f, 0.5f, 20, 20);
    glPopMatrix();

    // Chimney
    glColor3f(0.6f, 0.6f, 0.6f);  // Dark gray
    glPushMatrix();
    glTranslatef(0.5f, 1.2f, 0.0f);
    glScalef(0.2f, 0.6f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Door
    glColor3f(0.4f, 0.2f, 0.0f);  // Brown
    glPushMatrix();
    glTranslatef(0.7f, 0.0f, 0.0f);
    glScalef(0.3f, 0.6f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Door knob
    glColor3f(0.8f, 0.8f, 0.0f);  // Yellow
    glPushMatrix();
    glTranslatef(0.85f, 0.1f, 0.1f);
    glutSolidSphere(0.03f, 10, 10);
    glPopMatrix();

    // Windows
    glColor3f(0.6f, 0.8f, 1.0f);  // Light blue
    glPushMatrix();
    glTranslatef(-0.4f, 0.3f, 0.6f);
    glScalef(0.3f, 0.3f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4f, 0.3f, -0.6f);
    glScalef(0.3f, 0.3f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Window frames
    glColor3f(1.0f, 1.0f, 1.0f);  // White
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    // Front window frame
    glVertex3f(-0.55f, 0.15f, 0.61f);
    glVertex3f(-0.25f, 0.15f, 0.61f);
    glVertex3f(-0.4f, 0.15f, 0.61f);
    glVertex3f(-0.4f, 0.45f, 0.61f);
    // Back window frame
    glVertex3f(-0.55f, 0.15f, -0.61f);
    glVertex3f(-0.25f, 0.15f, -0.61f);
    glVertex3f(-0.4f, 0.15f, -0.61f);
    glVertex3f(-0.4f, 0.45f, -0.61f);
    glEnd();
}
void tree() {
    // Trunk
    glColor3f(0.6f, 0.4f, 0.2f);  // Brown
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glScalef(0.4f, 1.5f, 0.4f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Lower branches
    glColor3f(0.0f, 0.6f, 0.0f);  // Green
    glPushMatrix();
    glTranslatef(0.0f, 1.2f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glutSolidCone(0.8f, 1.0f, 20, 20);
    glPopMatrix();

    // Middle branches
    glColor3f(0.0f, 0.7f, 0.0f);  // Lighter green
    glPushMatrix();
    glTranslatef(0.0f, 1.6f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glutSolidCone(0.6f, 0.8f, 20, 20);
    glPopMatrix();

    // Upper branches
    glColor3f(0.0f, 0.8f, 0.0f);  // Lightest green
    glPushMatrix();
    glTranslatef(0.0f, 2.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glutSolidCone(0.4f, 0.6f, 20, 20);
    glPopMatrix();

    // Decorative spheres
    glColor3f(1.0f, 0.0f, 0.0f);  // Red
    glPushMatrix();
    glTranslatef(-0.3f, 1.4f, 0.0f);
    glutSolidSphere(0.1f, 10, 10);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 0.0f);  // Yellow
    glPushMatrix();
    glTranslatef(0.3f, 1.8f, 0.0f);
    glutSolidSphere(0.1f, 10, 10);
    glPopMatrix();

    glColor3f(0.0f, 0.0f, 1.0f);  // Blue
    glPushMatrix();
    glTranslatef(0.0f, 2.2f, 0.3f);
    glutSolidSphere(0.1f, 10, 10);
    glPopMatrix();
}
void drawGround() {
    glColor3f(0.6f, 0.8f, 0.6f);  // Light green color for the ground
    glBegin(GL_QUADS);
    glVertex3f(-10.0f, -0.1f, -10.0f);
    glVertex3f(-10.0f, -0.1f, 10.0f);
    glVertex3f(10.0f, -0.1f, 10.0f);
    glVertex3f(10.0f, -0.1f, -10.0f);
    glEnd();
}

void car() {
    // Body
    glColor3f(1.0f, 0.0f, 0.0f);  // Red
    glPushMatrix();
    glScalef(2.0f, 0.5f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Roof
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glScalef(1.5f, 0.5f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Wheels
    glColor3f(0.2f, 0.2f, 0.2f);  // Dark gray
    glPushMatrix();
    glTranslatef(-0.7f, -0.3f, 0.5f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glutSolidTorus(0.1f, 0.2f, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7f, -0.3f, -0.5f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glutSolidTorus(0.1f, 0.2f, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7f, -0.3f, 0.5f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glutSolidTorus(0.1f, 0.2f, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7f, -0.3f, -0.5f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glutSolidTorus(0.1f, 0.2f, 20, 20);
    glPopMatrix();

    // Headlights
    glColor3f(1.0f, 1.0f, 0.0f);  // Yellow
    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0.3f);
    glutSolidSphere(0.1f, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0f, 0.0f, -0.3f);
    glutSolidSphere(0.1f, 10, 10);
    glPopMatrix();
}
