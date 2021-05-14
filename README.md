# msixty [![Build status](https://circleci.com/gh/tradingview/msixty.svg?style=svg)](https://circleci.com/gh/tradingview/msixty)

Making your [MSIX](https://docs.microsoft.com/en-us/windows/msix/) experience ten times better!

## Working environment setup

This project uses:
- [python 3.7](https://www.python.org/);
- [`pipenv`](https://pipenv.pypa.io/) for working environment management;
- [lefthook](https://github.com/Arkweid/lefthook/releases) for working with git hooks;

It is assumed that abovementioned tools and files are already present in a target system and available for invocation or use.

### Create virtual environment and install dependencies:
```
# set this variable to place virtual environment inside a project's directory
$ export PIPENV_VENV_IN_PROJECT=1

$ pipenv install
```

### Initialize git hooks:
Initialize lefthook with the following command
`lefthook install`

## Run conan for creating package:
```
$ pipenv run conan create . 1.2.3.4@tradingview/testing -s compiler.cppstd=17 --profile x86_64-Windows-v142-Debug -tbf out\\test_package_build\\x86_64-Debug
```