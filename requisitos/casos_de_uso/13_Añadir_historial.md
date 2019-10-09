## Añadir historial médico

**ID**:13 **Descripción**: El secretario selecciona un paciente al que añadir el historial médico
**Actor principal**: Secretario
**Actor secundario**: Paciente

**Precondiciones**: Ninguna

**Flujo principal**:
1. El secretario desea añadir un historial médico a un paciente
2. El secretario abre el cuadro de diálogo de búsqueda en el menú principal con el caso de uso de buscar paciente
3. El secretario inserta el nombre y el apellido del paciente
4. Una vez encontrado el paciente, el sistema muestra un campo a rellenar con el historial médico
5. Se mostrará un mensaje diciendo que se ha añadido correctamente

**Postcondiciones**:  Ninguna

**Flujos alternativos**:
* Si el usuario no está registrado como cliente, se mostrará un mensaje que lo indique.
* Si al paciente ya tiene un historial médico, se mostrará un mensaje de error.
