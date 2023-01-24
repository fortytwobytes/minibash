# minishell

TODO:
*	add TTY, SHLVL to the env they are dynamic
*	

SIGKILL:
*	reduce the shlvl -1
*	if here_doc
	*	delete the tmp file in /tmp/.here_doc_id, the id is used if the user opened multiple heredocs in different terminals, we can use the tty variable for it
	* print a custom error message like macos bash

