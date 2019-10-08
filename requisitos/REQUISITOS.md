# Descripción de la aplicación
Es necesario el desarrollo de un software de gestión para una clínica medica. Este software será utilizado por la secretaría de la clínica y los doctores para registrar los datos relativos a los pacientes, las citas, el tratamiento y el historial médico pasado.
Se ha realizado una entrevista al cliente para la aclaración de las funcionalidades del software de gestión y diseño. 

# Datos de la aplicación
Se ha determinado que los datos que debe almacenar la aplicación son los siguientes:
* **Datos personales pacientes**
    * Nombre
    * Apellidos
    * Domicilio
    * Número de teléfono
    * Fecha de nacimiento
    * Seguro/privado.
* **Citas**
    * Fecha y hora
    * Nombre del paciente
    * Descripción de la cita
* **Tratamiento**
    * Nombre
    * Fecha de inicio
    * Fin de tratamiento
    * Regularidad
    * Concentración
    * Dosis (cantidad)
* **Historial médico**
    * Descripción
    * Fecha de la realización del historial


# Requisitos funcionales
Los requisitos funcionales son declaraciones de los servicios que proveerá el sistema, de la manera en que éste reaccionará a entradas particulares.
* **Datos personales pacientes:** Añadir nuevos pacientes, modificar los datos de los pacientes, borrar un paciente totalmente, mostrar todos los pacientes. Búsqueda por apellido, por nombre o por nombre y apellidos que al poner el nombre se muestre todos sus datos.
* **Citas:** Añadir nuevas citas, cancelarlas, modificarlas. Consultar las citas de un paciente bucándolo por su nombre y apellidos (no es key sensitive). Al iniciar el programa se mostrarán las citas previstas para el día actual. Antes de una cita creamos un archivador a un paciente.
* **Tratamiento:** Modificar el tratamiento, cambiar la dosis. Si el paciente finalizó el tratamiento, que la información del tratamiento no se pueda modificar; si está en tratamiento, que sí se pueda modificar.
* **Historial médico:** Añadir o cambiar la descripción del historial médico.


# Requisitos no funcionales
Son aquellos requisitos que no se refieren directamente a las funciones específicas que entrega el sistema, sino a las propiedades emergentes de éste como la fiabilidad, la respuesta en el tiempo y la capacidad de almacenamiento. Definen las restricciones del sistema como la capacidad de los dispositivos de entrada/salida y la representación de datos que se utiliza en la interface del sistema.
* El cliente dispone de un computador personal con Linux.
* El lenguaje de implementación C++.
* La interfaz gráfica del sistema sera la misma consola de Linux
* Incluir el nombre de la clínica en la aplicación, que es el de la doctora.
* En las búsquedas que se realicen no afectarán los acentos ni las mayúsculas ni minúsculas, es decir, no será key sensitive.
* Se hará una copia de seguridad diaria justo al iniciar el programa.
* Entrega el 23 de diciembre.


# Funcionalidades priorizadas
1. Poder ver las consultas previstas para el día actual.
2. Añadir nuevas citas, modificarlas y cancelarlas. Consultar las citas de un paciente dado.
3. Consultar datos personales de un paciente.
4. Añadir nuevos pacientes, modificarlos y eliminar pacientes ya existentes.
5. Añadir y modificar el tratamiento.
6. Añadir y cambiar la descripción del historial médico.



