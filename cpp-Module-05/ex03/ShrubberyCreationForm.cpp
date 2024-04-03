#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("Shrubbery Creation Form", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : Form(copy), target(copy.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    (void)other;
    return *this;
}

void ShrubberyCreationForm::executeAction(Bureaucrat const &executor) const
{
    (void) executor;
    std::ofstream ofs((this->target + "_shrubbery").c_str());

    if (!ofs)
        throw std::runtime_error("unable to create a file!");

    ofs << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
    ofs << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
    ofs << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
    ofs << "         {\\{/(/\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
    ofs << "        {/{/(_)/}{\\{/(\\)\\}{\\(_){/}/}/}/}" << std::endl;
    ofs << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
    ofs << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
    ofs << "      _{\\{/{\\{\\/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
    ofs << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
    ofs << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
    ofs << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
    ofs << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
    ofs << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
    ofs << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
    ofs << "          (_) {/{\\/}{\\{\\/}/}{\\{\\)/}/} (_)" << std::endl;
    ofs << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
    ofs << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl;
    ofs << "              {){/ {\\/}{\\/} \\}\\}" << std::endl;
    ofs << "              (_)  \\.-'.-/" << std::endl;
    ofs << "          __...--- |'-.-'| --...__" << std::endl;
    ofs << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl;
    ofs << " -\"    ' .  . '    |.'-._| '  . .  '   jro" << std::endl;
    ofs << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
    ofs << "          ' ..     |'-_.-|" << std::endl;
    ofs << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
    ofs << "              .'   |'- .-|   '." << std::endl;
    ofs << "  ..-'   ' .  '.   `-._.-�   .'  '  - ." << std::endl;
    ofs << "   .-' '        '-._______.-'     '  ." << std::endl;
    ofs << "        .      ~," << std::endl;
    ofs << "    .       .   |\\   .    ' '-." << std::endl;
    ofs << "    ___________/  \\____________" << std::endl;
    ofs << "   /  Why is it, when you want \\" << std::endl;
    ofs << "  |  something, it is so damn   |" << std::endl;
    ofs << "  |    much work to get it?     |" << std::endl;
    ofs << "   \\___________________________/" << std::endl;

    ofs.close();
}