## Modificar paciente
 
**ID**: 09 **Descripción**: El secretario selecciona un paciente al que modificar sus datos personales  
**Actor principal**: Secretario
**Actor secundario**: Paciente
 
**Precondiciones**: Para modificar los datos personales de un paciente éste debe existir en el sistema
 
**Flujo principal**:
1. El secretario desea modificar los datos personales de un paciente
2. El secretario abre el cuadro de diálogo de búsqueda en el menú principal con el caso de uso de buscar paciente
3. El sistema muestra los datos personales de ese paciente
4. El secretario elige qué campo(s) desea modificar
5. El secretario rellena los nuevos datos del paciente
6. Se mostrará un mensaje de éxito si los datos han sido modificados satisfactoriamente
 
**Postcondiciones**:  Ninguna
 
**Flujos alternativos**:  
2.a Se mostrará un mensaje de error si el paciente no se encuentra en la base de datos  
6.a Se mostrará un mensaje de error si uno o más campos no han sido introducidos correctamente  

