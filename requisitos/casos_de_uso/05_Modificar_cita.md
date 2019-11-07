## Modificar cita
 
**ID**: 05 **Descripción**: El secretario selecciona un paciente al que modificar la cita  
**Actor principal**: Secretario
**Actor secundario**: Paciente
 
**Precondiciones**: Ninguna
 
**Flujo principal**:
1. El secretario desea modificar la cita a un paciente
2. El secretario abre el cuadro de diálogo de búsqueda en el menú principal con el caso de uso de buscar paciente
3. Una vez que se ha encontrado al paciente, el secretario accede a la opción "Modificar citas"
4. El sistema muestra las citas que tiene ese paciente
5. El secretario elige que cita modificar
6. El secretario introduce los nuevos datos de la cita: la fecha, hora de inicio y finalización y la descripción de la cita
7. Se mostrará un mensaje indicando si la cita se ha modificado satisfactoriamente
 
**Postcondiciones**:  Ninguna
 
**Flujos alternativos**:  
3.a Si el paciente no está registrado se mostrará un mensaje que lo indique  
4.a Si el paciente no tiene ninguna cita concertada, se mostrará un mensaje que lo indique  
6.a Si la nueva fecha u hora introducida se solapa con otra cita ya concertada, no quedará introducida esta modificación de la cita y se pedirá otra fecha/hora.
