# minishell

TODO:
*	add TTY, SHLVL to the env they are dynamic
*	

SIGKILL:
*	reduce the shlvl -1
*	if here_doc
	*	delete the tmp file in /tmp/.here_doc_id, the id is used if the user opened multiple heredocs in different terminals, we can use the tty variable for it
	* print a custom error message like macos bash


# Some corner cases
*	export a =12 ==> bash: export: `=12': not a valid identifier
*	export a= 12 ==> bash: export: `12': not a valid identifier
*	"export var='this is a string'" ==> bash: export var='this is a string': command not found
*	export str="" ==> str=
*	export str=   ==> this should not work
*	export var$1=value ==> var=value