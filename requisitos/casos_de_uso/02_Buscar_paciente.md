## Buscar paciente

**ID**:02  **Descripción**: El secretario realiza una búsqueda de un paciente concreto para después realizar alguna acción

**Actor principal**: Secretario
**Actor secundario**: Paciente


**Precondiciones**: Ninguna

**Flujo principal**:
1. El secretario desea buscar un paciente
2. El secretario accede a la opción "Buscar paciente"
3. El secretario inserta el nombre y el apellido del paciente
4. El sistema muestra los resultados que coinciden con el nombre y apellido introducidos

**Postcondiciones**:
* El secretario puede concertar, modificar y cancelar una cita con el paciente
* El secretario puede añadir o modificar el tratamiento actual al paciente
* El secretario puede añadir una entrada al historial médico del paciente
* El secretario puede modificar o eliminar el paciente.

**Flujos alternativos**:  
4.a Si no hay ningún paciente que coincida con los datos buscados, no se mostrará ningún paciente se dará un mensaje de error
