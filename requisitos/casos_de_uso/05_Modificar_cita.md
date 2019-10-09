## Modificar cita
 
**ID**: 05 **Descripción**: El secretario selecciona un paciente al que modificar la cita  
**Actor principal**: Secretario
**Actor secundario**: Paciente
 
**Precondiciones**: Para modificar una cita tiene que existir una
 
**Flujo principal**:
1. El secretario desea modificar la cita a un paciente
2. El secretario abre el cuadro de diálogo de búsqueda en el menú principal con el caso de uso de buscar paciente
3. Una vez que se ha encontrado al paciente, el secretario accede a la opción "Modificar citas"
4. El sistema muestra las citas que tiene ese paciente
5. El secretario elige que cita modificar
6. El secretario rellena los nuevos datos de la cita
7. Se mostrará un mensaje diciendo que la cita se ha modificado satisfactoriamente
 
**Postcondiciones**:  Ninguna
 
**Flujos alternativos**:  
* Si el paciente no está registrado se mostrará un mensaje que lo indique
