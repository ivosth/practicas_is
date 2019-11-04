## Añadir nuevas citas

**ID**: 03
**Descripción**: Se añade una cita a un usuario previamente buscado por nombre y apellidos

**Actores principales**: Secretario
**Actores secundarios**: Paciente


**Precondiciones**:
* Ninguna

**Flujo principal**:
1. El secretario desea añadir una nueva cita
1. El secretario abre el cuadro de diálogo de búsqueda en el menú principal con el caso de uso de buscar paciente
1. Una vez encontrado el paciente, el secretario accede a la opción "Añadir citas"
1. El sistema pide los datos de la cita, la fecha y hora de inicio y finalización, el nombre del paciente y la descripción de la cita
1. El secretario introduce los datos de la cita, la fecha y hora de inicio y finalización, el nombre del paciente y la descripción de la cita
1. El sistema muestra si se ha realizado correctamente la cita

**Postcondiciones**:

* Ninguna

**Flujos alternativos**:

3.a Si en la búsqueda del paciente no se encuentra se mostrará un mensaje de error. 
5.a Si los parámetros introducidos nos son correctos se mostrará un mensaje de error.
5.b Si la fecha de la nueva cita introducida se solapa con otra ya concertada, no quedará introducida esta nueva cita y se pedirá otra fecha/hora.
