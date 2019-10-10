## Modificar historial médico

**ID**:14 **Descripción**: El secretario selecciona un paciente al que modificar el historial médico  

**Actor principal**: Secretario
**Actor secundario**: Paciente

**Precondiciones**: Ninguna

**Flujo principal**:
1. El secretario desea modificar el historial médico a un paciente
2. El secretario abre el cuadro de diálogo de búsqueda en el menú principal con el caso de uso de buscar paciente
3. El secretario inserta el nombre y el apellido del paciente
4. Una vez encontrado el paciente, el sistema muestra un campo con el historial médico actual del paciente
5. El secretario puede modificar el historial médico
6. Se mostrará un mensaje diciendo que el historial médico se ha modificado correctamente.

**Postcondiciones**:  Ninguna

**Flujos alternativos**:
* Si el usuario no está registrado como cliente, se mostrará un mensaje que lo indique.
* Si al paciente aún no tiene ningún historial médico asociado, se mostrará un mensaje de error