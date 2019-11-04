## Modificar tratamiento

**ID**:12 **Descripción**: El secretario selecciona un paciente al que modificar el tratamiento  

**Actor principal**: Secretario
**Actor secundario**: Paciente

**Precondiciones**: El tratamiento a modificar debe ser el actual (entradas pasadas no se pueden modificar)

**Flujo principal**:
1. El secretario desea modificar el tratamiento a un paciente
2. El secretario abre el cuadro de diálogo de búsqueda en el menú principal con el caso de uso de buscar paciente
3. Una vez encontrado el paciente, el sistema muestra un campo con el tratamiento actual del paciente
4. El secretario puede modificar el tratamiento actual
5. Se mostrará un mensaje indicando si el tratamiento se ha modificado correctamente

**Postcondiciones**:  Ninguna

**Flujos alternativos**:  
2.a Si el paciente no existe, se mostrará un mensaje de error.  
4.a Si al paciente aún no tiene ningún tratamiento asociado, se mostrará un mensaje de error
