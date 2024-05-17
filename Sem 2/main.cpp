#include </opt/homebrew/Cellar/freeglut/3.4.0/include/GL/freeglut.h>

// Функция отрисовки
void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT); // Очистка экрана

    glBegin(GL_TRIANGLES); // Начало определения треугольников
        glVertex3f(-0.5, -0.5, 0.0); // Вершина 1
        glVertex3f(0.5, -0.5, 0.0);  // Вершина 2
        glVertex3f(0.0, 0.5, 0.0);   // Вершина 3
    glEnd(); // Конец определения треугольников

    glutSwapBuffers(); // Переключение буферов
}

int main(int argc, char **argv) {
    glutInit(&argc, argv); // Инициализация GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // Установка режима отображения
    glutInitWindowSize(800, 600); // Установка размеров окна
    glutCreateWindow("OpenGL Test"); // Создание окна с заголовком "OpenGL Test"

    glutDisplayFunc(renderScene); // Установка функции отрисовки

    glClearColor(0.0, 0.0, 0.0, 1.0); // Установка цвета очистки экрана (черный)

    glutMainLoop(); // Главный цикл GLUT

    return 0;
}
