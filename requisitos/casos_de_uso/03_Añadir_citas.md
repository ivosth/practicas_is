## Añadir nuevas citas

**ID**: 03
**Descripción**: Se añade una cita a un usuario previamente buscado por nombre y apellidos

**Actores principales**: Secretario
**Actores secundarios**: Paciente


**Precondiciones**:
* El paciente debe estar dado de alta en el sistema

**Flujo principal**:
1. El secretario desea añadir una nueva cita
1. El secretario abre el cuadro de diálogo de búsqueda en el menú principal
1. El sistema pide los datos de la cita, la fecha y hora, el nombre del paciente y la descripción de la cita
1. El secretario introduce los datos de la cita, la fecha y hora, el nombre del paciente y la descripción de la cita
1. El sistema muestra si se ha realizado correctamente la cita

**Postcondiciones**:

* Ninguna

**Flujos alternativos**:

4.a. Si los parámetros introducidos nos son correctos se mostrará un mensaje de error
