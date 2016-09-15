#ifndef RWFILE_H_INCLUDED
#define RWFILE_H_INCLUDED
FILE* AbreArquivo(const char *nome, const char *tipoArquivo);
void LeDadosTXT(FILE *arq);
void LeCabecalhoBin(FILE *arq, int *sizeListaSEMREP, int *sizeListaCOMREP);
void LeDadosBin(FILE *arq, int size);
void GravaListaSEMREPBinario(FILE *arq, int size);
void GravaListaCOMREPBinario(FILE *arq, int size);
void GravaArquivoBinario();
#endif // RWFILE_H_INCLUDED
