## Añadir tratamiento

**ID**:11 **Descripción**: El secretario selecciona un paciente al que añadir un tratamiento  

**Actor principal**: Secretario
**Actor secundario**: Paciente

**Precondiciones**: Ninguna

**Flujo principal**:
1. El secretario desea añadir un tratamiento a un paciente
2. El secretario abre el cuadro de diálogo de búsqueda en el menú principal con el caso de uso de buscar paciente
3. Una vez encontrado el paciente, el sistema muestra un campo a rellenar con el nuevo tratamiento
4. Se mostrará un mensaje diciendo que el tratamiento se ha añadido correctamente

**Postcondiciones**:  Ninguna

**Flujos alternativos**:  
3.a Si el paciente no existe, se mostrará un mensaje que lo indique.  
3.b Si al paciente ya se le ha dado un tratamiento, se mostrará un mensaje de error.
