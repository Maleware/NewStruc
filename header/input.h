
#define RI_INSUFFICIENT_BUFFER_SIZE -1
#define RI_EOF -2

#define II_NOINTERPRET -1
#define II_NAN -2
#define II_MALFORMED -3
#define II_WHITE_SPACE 1

#define EI_EXIT 1
#define EI_UNKNOWN_ACTION -1
#define EI_EX_DETER_FAILED -2

#define EE_UNKNOWN_EXNO -10

#define IEN_NOINTERPRET -1
#define IEN_WHITE_SPACE 1


#define IN_SZ 10

typedef enum
{
	None,
	Exit,
	Help,
	ExecuteExample,
	ExecuteAll,
	ExecuteStructure,
	ExecuteDynArray,
	ExecuteIAfunct,
	ExecuteAtFiDi,
	ExecuteWwvla,
	ExecuteAhaf,
	ExecuteDynDaStr,
}II_Action;

int readInput(char* buf, unsigned int bufsz, unsigned int* outlen);
int interpretInput(const char* in, unsigned int insz, II_Action* action);
int interpretExNo(const char* in, unsigned int insz, int* exampleNo);
int executeExample(int exNo);
int executeStructure(int exNo);
int executeDynArray(int exNo);
int executeIAfunct(int exNo);
int executeAtFiDi(int exNo);
int executeWwvla(int exNo);
int executeAhaf(int exNo);
int exectueDynDaStr(int exNo);
int help(void);
int executeInput(II_Action action, const char* in, unsigned int insz);
