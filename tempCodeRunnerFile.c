while ((va_arg(args, char*)) != (char*)'\n')         //(va_arg(args, char*)) != (char*)'\n' để hết warning
    {
        result += va_arg(check, int);
    }