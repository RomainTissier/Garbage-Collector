#!/bin/python3

import sys


def printC_enum(enum_name, enum):
    """
        Print the C "toString" function.
    """
    print("char* "+enum_name+"_toString("+enum_name+" value)")
    print("{")
    print("        char *res;")
    print("        switch(value) {")

    for value in enum:
        print("                case "+value.rstrip()+": res=\""
              ""+value.rstrip()+"\"; break;")

    print("                default: res=\"UNKNOWN\"; break;")
    print("        }")
    print("        return res;")
    print("}")


def printC_flags(enum_name, enum):
    """
        Print the C "toString" function.
    """
    print("void print_"+enum_name+"_flags("+enum_name+" value)")
    print("{")
    print("        printf(\"Print "+enum_name+" flags for 0x%x :\\n\", value);")

    for value in enum:
        print("        if((value&"+value.rstrip()+") == "+value.rstrip()+") {")
        print("                printf(\"    - "+value.rstrip()+"\\n\");")
        print("        }")

    print("}")


if __name__ == '__main__':
    enum = []
    if len(sys.argv) == 3:
        # Save enum name
        enum_name = sys.argv[1]

        # Save enum value from input file
        input_file_name = sys.argv[2]
        input_file = open(input_file_name, "r")
        for line in input_file:
            enum.append(line)

        # Print the C "toString function"
        printC_enum(enum_name, enum)
        printC_flags(enum_name, enum)
    else:
        print("Usage : ./print_enum <enum_name> <input_file>")
