void agent() {
    // Head
    glColor3f(1.0f, 0.8f, 0.6f);  // Skin color
    glPushMatrix();
    glTranslatef(0.0f, 0.7f, 0.0f);
    glScalef(0.4f, 0.4f, 0.4f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Eyes
    glColor3f(1.0f, 1.0f, 1.0f);  // White
    glPushMatrix();
    glTranslatef(-0.1f, 0.7f, 0.21f);
    glScalef(0.1f, 0.1f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1f, 0.7f, 0.21f);
    glScalef(0.1f, 0.1f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Pupils
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    glPushMatrix();
    glTranslatef(-0.1f, 0.7f, 0.22f);
    glScalef(0.05f, 0.05f, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1f, 0.7f, 0.22f);
    glScalef(0.05f, 0.05f, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Mouth
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.21f);
    glScalef(0.2f, 0.05f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Body
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue shirt
    glPushMatrix();
    glTranslatef(0.0f, 0.3f, 0.0f);
    glScalef(0.5f, 0.6f, 0.3f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Arms
    glColor3f(1.0f, 0.8f, 0.6f);  // Skin color
    glPushMatrix();
    glTranslatef(-0.3f, 0.3f, 0.0f);
    glScalef(0.2f, 0.6f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3f, 0.3f, 0.0f);
    glScalef(0.2f, 0.6f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    

    // Legs
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue pants
    glPushMatrix();
    glTranslatef(-0.2f, -0.3f, 0.0f);
    glScalef(0.2f, 0.6f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, -0.3f, 0.0f);
    glScalef(0.2f, 0.6f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Feet
    glColor3f(0.4f, 0.2f, 0.0f);  // Brown shoes
    glPushMatrix();
    glTranslatef(-0.2f, -0.7f, 0.1f);
    glScalef(0.2f, 0.2f, 0.3f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, -0.7f, 0.1f);
    glScalef(0.2f, 0.2f, 0.3f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Hat
    glColor3f(0.6f, 0.3f, 0.0f);  // Brown hat
    glPushMatrix();
    glTranslatef(0.0f, 0.9f, 0.0f);
    glScalef(0.5f, 0.2f, 0.5f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glColor3f(0.6f, 0.3f, 0.0f);  // Brown hat brim
    glPushMatrix();
    glTranslatef(0.0f, 0.8f, 0.0f);
    glScalef(0.6f, 0.1f, 0.6f);
    glutSolidCube(1.0f);
    glPopMatrix();
}