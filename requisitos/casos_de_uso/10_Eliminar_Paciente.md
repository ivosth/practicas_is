## Eliminar paciente
 
**ID**: 10 **Descripción**: El secretario selecciona un paciente al que desea eliminar  
**Actor principal**: Secretario
**Actor secundario**: Paciente
 
**Precondiciones**: El paciente debe existir en el sistema para poder ser eliminado
 
**Flujo principal**:
1. El secretario desea eliminar un paciente
2. El secretario abre el cuadro de diálogo de búsqueda en el menú principal con el caso de uso de buscar paciente
3. El sistema muestra los datos de ese paciente
4. El secretario elige eliminar a dicho paciente
5. El sistema pide confirmar al secretario si está seguro de eliminar dicho paciente
6. Se mostrará un mensaje de éxito si el paciente se ha borrado del sistema satisfactoriamente
 
**Postcondiciones**:  Ninguna
 
**Flujos alternativos**: 
2.a Si el paciente no se encuentra en la base de datos, se mostrará otro mensaje de error.
5.a Si el paciente no ha podido ser eliminado, se mostrará un mensaje de error y no se eliminará a dicho paciente. El paciente tampoco será eliminado si el secretario no ha respondido afirmativamente a la última confirmación.
