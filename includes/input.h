#ifndef INPUT_H
# define INPUT_H

# include "term3d.h"

typedef struct e_input_error
{
	CORRECT,
	INVALID,
	TERMINATED
}	t_input_error;

t_input_error	input(t_rotation *rotation);

#endif
