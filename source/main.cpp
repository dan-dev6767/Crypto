#include <iostream>

#include <crypto.hpp>
#include <CLI/CLI.hpp>

int main(int argc, char* argv[])
{
	CLI::App app("Simple file encryptor");
	app.allow_windows_style_options();

	// App Arguments

	CLI11_PARSE(app, argc, argv);

	// App Logic

	return 0;
}