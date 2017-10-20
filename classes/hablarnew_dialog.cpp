#include "hablarnew_dialog.h"

std::string getResponse(int step, std::string* variableNames) {
    switch(step) {
    case 0: return "¿Pues&.&.&. quieres hablar?? Primero tienes que decirme su nombre. Escribe tu nombre por favor.\n";
    case 1: return "¿Qué? ¡Es un nombre tan largo! Ya no puedo recordar. Dime otra vez por favor.\n";
    case 2: return "¿Eso es su nombre?&& Hmm.&.&.& Supongo que lo suficiente. Pues,&& Dime algo sobre de ti.\n";
    case 6:
        {
        std::string adressForm, name = "";
        if (variableNames[1] == "M")
            adressForm = "señor ";
        else if (variableNames[1] == "F")
            adressForm = "señorita ";
        else
            adressForm = ".&.&.&Viajero&&/a ";
        name = variableNames[0];
        return "Vale " + adressForm + name + ". Ya se nota que divertiremos mucho. Di mas. ¡Quiero saber todo sobre de ti!\n"
        "Deja me ayudarte para describir tu personalidad. Escoge algunes rasgos típico para ti.";
        }
    case 7:
        {
            std::string gender = *variableNames;
            std::string adressForm = "Hombre, ";
            if (gender == "F")
                adressForm = "Chica, ";
            else if (gender == "N")
                adressForm = "Viajero, ";
            return "!Guau, son tantos! Quieres ser el todo a la vez? " + adressForm + "tranquilo. No puedes tener todo.\n"
            + "Dije escoge, pero cuando eliges todo no es escoger. Inténtalo de nuevo por favor. Y no mas que 12 opciones";
        }
    case 8: return "¿Qué? Es todo? No lo creo, eres demasiado humilde. En este mundo uno debe coger lo que es suyo. Seguramente hay más de "
    + *variableNames + "cosas que uno puede decir sobre ti. Por favor, escoge al menos cuatro opciones.";
    case 9: return "Vale. Estoy empezando entender a ti. Tengo algunas preguntas para ti. Pero primero, dime algo de tus aficiones.";
    case 10:
        if (variableNames[0] == "true")
            return "¿De verdad, otra vez? Eres tan aburrid" + variableNames[2] + " que no hay nada que decir sobre ti?\n"
            "¡No lo acepto! Todo mundo es capace de tener al menos tres aficiones. Otra vez.";
        else
            return "¿Hmm&.&.&.& hay pocos hobbies, no? ¿Seguramente son más cosas en este mundo que te interesan? Francamente, "
            "quiero que escoges tres aficiones al menos, no sea que piense que eres aburrido. ¿No es demasiado difficil espero?";
    case 11: return "¡Muy bien! En cuanto al las preguntas, ¡Aquí vienen!\nEntonces, tu y dos amigos están muriendo de hambre en "
            "el desierto. Esta agua, pero no sufficiente comida para sobrevivir. La unica manera para salvarte es matarte a los "
            "otros y comerlos. ¿Qué haces?";
    default: return "No sé que decir!";
    }
}

std::vector<std::string> getButtonNames(int step, std::string* variableNames) {
    std::vector<std::string> answer;
    if (step == 6) {
        std::string gender = "o";
        if (variableNames[1] == "F")
            gender = "a";
        answer.push_back("Soy divertid" + gender);
        answer.push_back("Cuando despierto, No. Simplemente no.");
        if (gender == "o")
            answer.push_back("Soy guapo (por supuesto)");
        else
            answer.push_back("Soy bonita (por supuesto)");
        answer.push_back("Estoy content" + gender);
        answer.push_back("Soy agradable");
        answer.push_back("Soy timid" + gender);
        answer.push_back("Soy valiente");
        answer.push_back("Soy leal");
        answer.push_back("Soy deportiv" + gender);
        answer.push_back("Soy caótic" + gender);
        answer.push_back("Soy inteligente");
        answer.push_back("Yo hablo mucho");
        answer.push_back("Soy optimista");
        answer.push_back("Soy obstinad" + gender);
        answer.push_back("Ya estoy aburrido. ¿Qué inquisición es esta?");
        answer.push_back("Por el amor de Dios, para ya!");
        answer.push_back("Soy paciente");
    }
    return answer;
}
