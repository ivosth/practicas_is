# Partes implicadas
* Cliente
* Desarrolladores

# Datos de la aplicación
Se ha determinado que los datos que debe almacenar la aplicación son los siguientes:
* **Datos personales pacientes**
    * Nombre
    * Apellidos
    * Domicilio
    * Número de teléfono
    * Fecha de nacimiento
    * Seguro particular/por mutua
* **Citas**
    * Fecha y hora de inicio y finalización
    * Nombre y apellidos del paciente
    * Descripción de la cita
* **Tratamiento**
    * Nombre y apellidos del paciente
    * Fecha de inicio
    * Fin de tratamiento
    * Regularidad
    * Concentración
    * Dosis (cantidad)
* **Historial médico**
    * Nombre y apellidos del paciente
    * Descripción
    * Fecha de la realización del historial


# Requisitos funcionales
Los requisitos funcionales son declaraciones de los servicios que proveerá el sistema, de la manera en que éste reaccionará a entradas particulares.
* **Datos personales pacientes:** Añadir nuevos pacientes, modificar los datos de los pacientes, borrar un paciente totalmente, mostrar todos los pacientes. Búsqueda por apellido, por nombre o por nombre y apellidos que al poner el nombre se muestre todos sus datos.
* **Citas:** Añadir nuevas citas, cancelarlas, modificarlas. Consultar las citas de un paciente bucándolo por su nombre y apellidos (no se distinguen mayúsculas/minúsculas ni acentos). Al iniciar el programa se mostrarán las citas previstas para el día actual. Antes de una cita creamos un archivador a un paciente.
* **Tratamiento:** Modificar el tratamiento actual, cambiar la dosis actual. Si el paciente finalizó el tratamiento, las entradas pasadas del tratamiento no se podrán modificar; si está en tratamiento, sí se puede modificar.
* **Historial médico:** Añadir o cambiar la descripción del historial médico actual. Las entradas pasadas no se podrán modificar.


# Requisitos no funcionales
Son aquellos requisitos que no se refieren directamente a las funciones específicas que entrega el sistema, sino a las propiedades emergentes de éste como la fiabilidad, la respuesta en el tiempo y la capacidad de almacenamiento. Definen las restricciones del sistema como la capacidad de los dispositivos de entrada/salida y la representación de datos que se utiliza en la interface del sistema.
* El sistema debe correr sobre el computador personal del cliente, que utiliza un SO Linux.
* El lenguaje de implementación C++.
* La interfaz gráfica del sistema sera la misma consola de Linux.
* En las búsquedas que se realicen no afectarán los acentos ni las mayúsculas ni minúsculas, es decir, no será "case sensitive".
* Se hará una copia de seguridad diaria justo al iniciar el programa.
* Entrega el 23 de diciembre.


# Funcionalidades priorizadas
1. Poder ver las consultas previstas para el día actual.
2. Añadir nuevas citas, modificarlas y cancelarlas. Consultar las citas de un paciente dado.
3. Consultar datos personales, historial médico y tratamiento(s) de un paciente.
4. Añadir nuevos pacientes, modificarlos y eliminar pacientes ya existentes.
5. Añadir y modificar el tratamiento.
6. Añadir y cambiar la descripción del historial médico.



