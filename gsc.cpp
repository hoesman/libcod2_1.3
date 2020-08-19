#include "gsc.hpp"

const char *stackGetParamTypeAsString(int param)
{
	if (param >= Scr_GetNumParam())
		return "UNDEFINED";

	VariableValue *var;
	var = &scrVmPub.top[-param];

	switch (var->type)
	{
	case 0:
		return "UNDEFINED";

	case 1:
		return "OBJECT";

	case 2:
		return "STRING";

	case 3:
		return "LOCALIZED_STRING";

	case 4:
		return "VECTOR";

	case 5:
		return "FLOAT";

	case 6:
		return "INT";

	case 7:
		return "CODEPOS";

	case 8:
		return "PRECODEPOS";

	case 9:
		return "FUNCTION";

	case 10:
		return "STACK";

	case 11:
		return "ANIMATION";

	case 12:
		return "DEVELOPER_CODEPOS";

	case 13:
		return "INCLUDE_CODEPOS";

	case 14:
		return "THREAD_LIST";

	case 15:
		return "THREAD_1";

	case 16:
		return "THREAD_2";

	case 17:
		return "THREAD_3";

	case 18:
		return "THREAD_4";

	case 19:
		return "STRUCT";

	case 20:
		return "REMOVED_ENTITY";

	case 21:
		return "ENTITY";

	case 22:
		return "ARRAY";

	case 23:
		return "REMOVED_THREAD";

	default:
		return "UNKNOWN TYPE";
	}
}

void NULL_FUNC(void) {}

scr_function_t scriptFunctions[] =
{


#ifdef EXTRA_FUNCTIONS_INC
#include "extra/functions.hpp"
#endif

	{NULL, NULL, 0} /* terminator */
};

xfunction_t Scr_GetCustomFunction(const char **fname, qboolean *fdev)
{
	xfunction_t m = Scr_GetFunction(fname, fdev);

	if (m)
		return m;

	for (int i = 0; scriptFunctions[i].name; i++)
	{
		if (strcasecmp(*fname, scriptFunctions[i].name))
			continue;

		scr_function_t func = scriptFunctions[i];

		*fname = func.name;
		*fdev = func.developer;

		return func.call;
	}

	return NULL;
}

scr_method_t scriptMethods[] =
{

#ifdef EXTRA_METHODS_INC
#include "extra/methods.hpp"
#endif

	{NULL, NULL, 0} /* terminator */
};

xmethod_t Scr_GetCustomMethod(const char **fname, qboolean *fdev)
{
	xmethod_t m = Scr_GetMethod(fname, fdev);

	if (m)
		return m;

	for (int i = 0; scriptMethods[i].name; i++)
	{
		if (strcasecmp(*fname, scriptMethods[i].name))
			continue;

		scr_method_t func = scriptMethods[i];

		*fname = func.name;
		*fdev = func.developer;

		return func.call;
	}

	return NULL;
}

int stackGetParamType(int param)
{
	if (param >= Scr_GetNumParam())
		return STACK_UNDEFINED;

	VariableValue *var;
	var = &scrVmPub.top[-param];

	return var->type;
}

void stackError(const char *format, ...)
{
	char errorMessage[COD2_MAX_STRINGLENGTH];
	va_list va;

	va_start(va, format);
	vsnprintf(errorMessage, sizeof(errorMessage), format, va);
	va_end(va);

	errorMessage[COD2_MAX_STRINGLENGTH - 1] = '\0';

	Scr_Error(errorMessage);
}

int stackGetParams(const char *params, ...)
{
	va_list args;
	va_start(args, params);

	int errors = 0;

	for (size_t i = 0; i < strlen(params); i++)
	{
		switch (params[i])
		{
		case ' ': // ignore param
			break;

		case 'i':
		{
			int *tmp = va_arg(args, int *);
			if ( ! stackGetParamInt(i, tmp))
			{
				Com_DPrintf("\nstackGetParams() Param %i is not an int\n", i);
				errors++;
			}
			break;
		}

		case 'v':
		{
			float *tmp = va_arg(args, float *);
			if ( ! stackGetParamVector(i, tmp))
			{
				Com_DPrintf("\nstackGetParams() Param %i is not a vector\n", i);
				errors++;
			}
			break;
		}

		case 'f':
		{
			float *tmp = va_arg(args, float *);
			if ( ! stackGetParamFloat(i, tmp))
			{
				Com_DPrintf("\nstackGetParams() Param %i is not a float\n", i);
				errors++;
			}
			break;
		}

		case 's':
		{
			char **tmp = va_arg(args, char **);
			if ( ! stackGetParamString(i, tmp))
			{
				Com_DPrintf("\nstackGetParams() Param %i is not a string\n", i);
				errors++;
			}
			break;
		}

		case 'c':
		{
			unsigned int *tmp = va_arg(args, unsigned int *);
			if ( ! stackGetParamConstString(i, tmp))
			{
				Com_DPrintf("\nstackGetParams() Param %i is not a const string\n", i);
				errors++;
			}
			break;
		}

		default:
			errors++;
			Com_DPrintf("\nUnknown identifier [%s] passed to stackGetParams()\n", params[i]);
			break;
		}
	}

	va_end(args);
	return errors == 0; // success if no errors
}

int stackGetParamInt(int param, int *value)
{
	if (param >= Scr_GetNumParam())
		return 0;

	VariableValue *var;
	var = &scrVmPub.top[-param];

	if (var->type == STACK_FLOAT)
	{
		*value = var->u.floatValue;
		return 1;
	}

	if (var->type != STACK_INT)
		return 0;

	*value = var->u.intValue;

	return 1;
}

int stackGetParamFunction(int param, int *value)
{
	if (param >= Scr_GetNumParam())
		return 0;

	VariableValue *var;
	var = &scrVmPub.top[-param];

	if (var->type != STACK_FUNCTION)
		return 0;

	*value = var->u.codePosValue - scrVarPub.programBuffer;

	return 1;
}

int stackGetParamString(int param, char **value)
{
	if (param >= Scr_GetNumParam())
		return 0;

	VariableValue *var;
	var = &scrVmPub.top[-param];

	if (var->type != STACK_STRING)
		return 0;

	*value = SL_ConvertToString(var->u.stringValue);

	return 1;
}

int stackGetParamConstString(int param, unsigned int *value)
{
	if (param >= Scr_GetNumParam())
		return 0;

	VariableValue *var;
	var = &scrVmPub.top[-param];

	if (var->type != STACK_STRING)
		return 0;

	*value = var->u.stringValue;

	return 1;
}

int stackGetParamVector(int param, vec3_t value)
{
	if (param >= Scr_GetNumParam())
		return 0;

	VariableValue *var;
	var = &scrVmPub.top[-param];

	if (var->type != STACK_VECTOR)
		return 0;

	value[0] = *(float *)(var->u.vectorValue + 0);
	value[1] = *(float *)(var->u.vectorValue + 1);
	value[2] = *(float *)(var->u.vectorValue + 2);

	return 1;
}

int stackGetParamFloat(int param, float *value)
{
	if (param >= Scr_GetNumParam())
		return 0;

	VariableValue *var;
	var = &scrVmPub.top[-param];

	if (var->type == STACK_INT)
	{
		*value = var->u.intValue;
		return 1;
	}

	if (var->type != STACK_FLOAT)
		return 0;

	*value = var->u.floatValue;

	return 1;
}

int stackGetParamObject(int param, unsigned int *value)
{
	if (param >= Scr_GetNumParam())
		return 0;

	VariableValue *var;
	var = &scrVmPub.top[-param];

	if (var->type != STACK_OBJECT)
		return 0;

	*value = var->u.pointerValue;

	return 1;
}
