## Modificar tratamiento

**ID**:12 **Descripción**: El secretario selecciona un paciente al que modificar el tratamiento  

**Actor principal**: Secretario
**Actor secundario**: Paciente

**Precondiciones**: Ninguna

**Flujo principal**:
1. El secretario desea modificar el tratamiento a un paciente
2. El secretario abre el cuadro de diálogo de búsqueda en el menú principal con el caso de uso de buscar paciente
3. El secretario inserta el nombre y el apellido del paciente
4. Una vez encontrado el paciente, el sistema muestra un campo con el tratamiento actual del paciente
5. El secretario puede modificar el tratamiento
6. Se mostrará un mensaje diciendo que el tratamiento se ha modificado correctamente

**Postcondiciones**:  Ninguna

**Flujos alternativos**:  
4.a Si el usuario no está registrado como cliente, se mostrará un mensaje que lo indique.  
4.b Si al paciente aún no tiene ningún tratamiento asociado, se mostrará un mensaje de error
