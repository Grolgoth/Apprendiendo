#include "hablarnew_dialog.h"

std::string getResponse(int step, std::string* variableNames) {
    switch(step) {
    case 0: return "Pues&.&.&. quieres hablar?? Primero tienes que decirme su nombre. Escribe tu nombre por favor.\n";
    case 1: return "Que? !Es un nombre tan largo! Ya no puedo recordar. Dime otra vez por favor.\n";
    case 2: return "Eso es su nombre?&& Hmm.&.&.& Supongo que lo suficiente. Pues,&& Dime algo sobre de ti.\n";
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
        return "Vale " + adressForm + name + ". Ya se nota que divertiremos mucho. Di mas. Quiero saber todo sobre de ti!\n"
        + "Deja me ayudarte para describir tu personalidad. Escoge algunes rasgos típico para ti.";
        }
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
