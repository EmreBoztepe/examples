#define FUNC_REGISTER_SIZE (255)
#define FUNC_ID_MAX (127)
/* function pointer type */
typedef  uint8_t ( *callback_func_t ) ( uint8_t * p_data, uint16_t len );
typedef struct {
    uint8_t           function_id;
    callback_func_t p_callback_func;
} function_register_t;

/* An array of functions handlers each with an id.*/
static function_register_t func_register[FUNC_REGISTER_SIZE];

/* Register function callback (function codes + functions) */
uint8_t RegisterCallback (uint8_t function_id, callback_func_t p_callback_func ) 
{
    uint8_t    status;
    if ((0 < function_id) && (function_id <= FUNC_ID_MAX)) 
    {
        /* Add function to the register */
        if ( p_callback_func != NULL ) 
        { 
            for (int i = 0; i < FUNC_REGISTER_SIZE; i++ ) 
            {
                if (( func_register[i].p_callback_func == NULL ) ||
                    ( func_register[i].p_callback_func == p_callback_func )) 
                    {
                        func_register[i].function_id = function_id;
                        func_register[i].p_callback_func = p_callback_func;
                        break;
                    }
            }
	    if (i != FUNC_REGISTER_SIZE) 
        {
		    status = SUCESSFULL;
	    }
	    else 
        {
		    status = FAILURE;
	    }
        }
        else { /*Remove function from the register */
            for ( i = 0; i < FUNC_REGISTER_SIZE; i++ ) {
                if ( func_register[i].function_id == function_id ) {
                    func_register[i].function_id = 0;
                    func_register[i].p_callback_func = NULL;
                    break;
                }
            }
            status = SUCESSFULL;
        }
    }
    else 
    {
        status = FAILURE; /* Invalid argument */
    }
    return status;
}

/*An example of how a callback function with a specific function code is called*/
uint8_t execute_callback(uint8_t FuncCode, uint8_t * p_data_buf, uint16_t len) 

{		
    uint8_t status;
    status = FAILURE;
    for( i = 0; i < FUNC_REGISTER_SIZE; i++ ){
        /* No more callbacks registered, exit. */
        if( func_register[i].function_id == 0 ){
            break;
        }
        else if( func_register[i].function_id == FuncCode) {
            status = func_register[i].p_callback_func( p_data_buf, len );
            break;
        }
     }
     return status;
}