## Cancelar cita
 
**ID**: 04 **Descripción**: El secretario selecciona un paciente al que cancelar la cita  
**Actor principal**: Secretario
**Actor secundario**: Paciente
 
**Precondiciones**: Ninguna
 
**Flujo principal**:
1. El secretario desea cancelar la cita a un paciente
1. El secretario abre el cuadro de diálogo de búsqueda en el menú principal con el caso de uso de buscar paciente
2. Una vez encontrado el paciente, el secretario accede a la opción "Cancelar cita"
4. El sistema muestra las citas que tiene ese paciente
5. El secretario elige que cita cancelar
7. Se mostrará un mensaje diciendo que la cita se ha cancelado satisfactoriamente
 
**Postcondiciones**:  Ninguna
 
**Flujos alternativos**:  
* Si el paciente no está registrado se mostrará un mensaje que lo indique.
* Si no existiese una ninguna cita que cancelar se notificará correspondientemente
