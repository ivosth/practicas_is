## Añadir tratamiento

**ID**:11 **Descripción**: El secretario selecciona un paciente al que añadir un tratamiento  

**Actor principal**: Secretario
**Actor secundario**: Paciente

**Precondiciones**: Ninguna

**Flujo principal**:
1. El secretario desea añadir un tratamiento a un paciente
2. El secretario abre el cuadro de diálogo de búsqueda en el menú principal con el caso de uso de buscar paciente
3. El secretario inserta el nombre y el apellido del paciente
4. Una vez encontrado el paciente, el sistema muestra un campo a rellenar con el nuevo tratamiento
5. Se mostrará un mensaje diciendo que el tratamiento se ha añadido correctamente

**Postcondiciones**:  Ninguna

**Flujos alternativos**:  
4.a Si el usuario no está registrado como cliente, se mostrará un mensaje que lo indique.  
4.b Si al paciente ya se le ha dado un tratamiento, se mostrará un mensaje de error.
