# Simulador Gráfico del Patrón de Diseño Publicador-Suscriptor (Tarea 3 - ELO329)

Este proyecto implementa un simulador gráfico del patrón de diseño Publicador-Suscriptor, siguiendo las especificaciones de la Tarea 3 del curso Diseño y Programación Orientados a Objetos (1er Semestre 2025). El simulador permite la interacción de diferentes tipos de publicadores y suscriptores a través de una interfaz gráfica desarrollada con la biblioteca Qt en C++.

## Descripción General

El simulador cuenta con dos tipos principales de publicadores y sus correspondientes suscriptores:

1.  **Publicador de Video (Tópico "Video")**:
    * Permite al usuario ingresar una URL de video a través de un campo de texto en la ventana principal.
    * Al presionar Enter en el campo de texto, la URL es publicada y el campo de texto es borrado.
    * El **Suscriptor de Video** asociado muestra un botón cuyo texto se actualiza con la última URL publicada.
    * Al presionar este botón, el suscriptor permite al usuario ver el video publicado.

2.  **Publicador de Posición GPS (Tópico "GPS")**:
    * Al crear este publicador, se solicita al usuario un nombre para el publicador y el tópico, y luego se abre un diálogo para seleccionar un archivo de texto con datos de posición usando `QFileDialog`.
    * El archivo de posiciones tiene el formato `<tiempo> <posición x> <posición y>` por línea.
    * El publicador lee este archivo e interpola linealmente las posiciones para publicar una actualización cada segundo, incluso si los intervalos en el archivo son mayores.
    * El **Suscriptor de GPS** abre una ventana separada donde muestra el tiempo y las coordenadas (x, y) del móvil. En la Etapa 4, también visualiza un círculo de color que representa el móvil y se mueve con las actualizaciones.

La interfaz gráfica principal organiza los publicadores en el lado izquierdo y los suscriptores en el lado derecho de la interfaz.

## Archivos del Proyecto

Este proyecto se corresponde con la **Etapa 4: Cumplimiento de las funcionalidades del simulador según secciones 2 y 3**. Los archivos que componen la solución son:

* `.pro`: Archivo de proyecto Qt.
* `main.cpp`: Punto de entrada de la aplicación.
* `mainwindow.h`, `mainwindow.cpp`, `mainwindow.ui`: Archivos para la ventana principal de la aplicación, que gestiona la interfaz global y la creación/activación de publicadores y suscriptores.
* `broker.h`, `broker.cpp`: Implementación de la clase `Broker`, central para el patrón Publicador-Suscriptor.
* `component.h`, `component.cpp`: Clase base abstracta para componentes del patrón (Publisher y Subscriber).
* `publisher.h`, `publisher.cpp`: Clase base abstracta para los publicadores.
* `subscriber.h`, `subscriber.cpp`: Clase base abstracta para los suscriptores.
* `videopublisher.h`, `videopublisher.cpp`: Implementación del publicador de URLs de video.
* `videofollower.h`, `videofollower.cpp`, `video.ui`: Implementación del suscriptor de video, incluyendo su propia interfaz gráfica para el botón y la reproducción.
* `gpscarpublisher.h`, `gpscarpublisher.cpp`: Implementación del publicador de posiciones GPS.
* `gpsfollower.h`, `gpsfollower.cpp`, `gpsfollower.ui`: Implementación del suscriptor de posiciones GPS, con su propia interfaz para la visualización del móvil y coordenadas.
* `README.md`: Este documento.
* `documentacion.pdf`: Archivo de documentación que incluye el diagrama de clases.
* `test.txt`: Un archivo de ejemplo con el formato de posiciones para el publicador GPS (como parte de la entrega de la etapa 3).

## Cómo Compilar

Para compilar este proyecto, necesitará tener instalado el **framework Qt (versión 5 o 6)** y un compilador C++ compatible (MinGW para Windows, GCC para Linux, Clang para macOS). Se recomienda utilizar **Qt Creator**.

**Abrir el Proyecto en Qt Creator:**
* Abra Qt Creator.
* Vaya a `File > Open File or Project...` y seleccione el archivo `Tarea_3_POO.pro`.
* Configure el kit de compilación deseado.

## Cómo Ejecutar

Una vez compilado, el ejecutable se encontrará en la carpeta de compilación (usualmente `build-YourProjectName-Desktop_Qt_...` o similar, dentro del directorio del proyecto).

**Desde Qt Creator:**
* Simplemente haga clic en el botón `Run` (el triángulo verde) en Qt Creator.


### Uso del Simulador:

Una vez ejecutado el programa:

* **Publicador de Video:** Localice el campo de texto y presione Enter en el campo de URL) en el lado izquierdo de la ventana principal. Ingrese una URL de video (ej. `http://profesores.elo.utfsm.cl/~aqv/elo329/1s22/Assignments/20220430 100849.mp4`) y presione Enter para publicarla. El botón del suscriptor de video se actualizará.
* **Suscriptor de Video:** Si su suscriptor de video se abre en una ventana separada, al publicarse una URL, su botón se actualizará. Haga clic en este botón para iniciar la reproducción del video.
* **Publicador de GPS:** Localice el botón "Crear Publicador GPS" en el lado izquierdo. Al hacer clic, se le pedirá el nombre del publicador y el tópico (se sugiere "GPS"). Posteriormente, se abrirá un diálogo de archivo para que seleccione el archivo de posiciones (`.txt`).
* **Suscriptor de GPS:** Al iniciar la simulación GPS, el suscriptor de GPS abrirá su propia ventana mostrando el avance del móvil en tiempo real (en segundos), incluyendo el tiempo y las coordenadas (x, y).

## Bonificación Extra (Extra-Crédito)

Este proyecto **HA** implementado la funcionalidad de **extra-crédito** de un `QSlider` para ajustar el volumen de reproducción del video. Esta característica se encuentra en la ventana del suscriptor de video y permite controlar el volumen de la reproducción.
