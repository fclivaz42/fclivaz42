#!/bin/bash

###########################################
# TURBO MEGA INSTALLATEUR 2 FOU 2 FCLIVAZ #
###########################################

cat > ~/.zshrc << EOF
export PATH="$HOME/bin:$PATH"
alias cat='bat'
export MANPAGER="sh -c 'col -bx | bat -l man -p'"
export BAT_PAGING=never
export BAT_PAGER=never

fastfetch
EOF

mkdir ~/bin && cd ~/bin
wget https://github.com/sharkdp/bat/releases/download/v0.24.0/bat-v0.24.0-x86_64-apple-darwin.tar.gz &>/dev/null
wget https://github.com/fastfetch-cli/fastfetch/releases/download/2.1.0/fastfetch-2.1.0-Darwin.tar.gz &>/dev/null
tar xf ./bat-v0.24.0-x86_64-apple-darwin.tar.gz bat-v0.24.0-x86_64-apple-darwin/bat --strip-components=1 &>/dev/null
tar xf ./fastfetch-2.1.0-Darwin.tar.gz fastfetch-2.1.0-Darwin/usr/bin/ --strip-components=3 &>/dev/null
rm ./*.gz &>/dev/null

mkdir ~/.config &>/dev/null
mkdir ~/.config/fastfetch &>/dev/null
bat --generate-config-file &>/dev/null
sed -i 's/#--theme="TwoDark"/--theme="Monokai Extended Bright"/g' ~/.config/bat/config &>/dev/null
sed -i 's/#--paging=never/--paging=never/g' ~/.config/bat/config &>/dev/null

cat > ~/.config/fastfetch/config.jsonc << EOF
{
    "$schema": "https://github.com/fastfetch-cli/fastfetch/raw/dev/doc/json_schema.json",
    "logo": {
        "type": "builtin",
        "source": "apple"
    },
    "display": {
        "color": "92",
        "separator": "\t"
    },
    "modules": [
        {
            "type": "title",
            "format": "\t   \u001b[1;94m{1}\u001b[0m @ \u001b[1;94m{2}"
        },
        {
            "type": "custom", // HardwareStart
            "format": "\u001b[38;2;51;204;255m┌────────────────────────────────────────────────────┐"
        },
        {
            "type": "os",
            "key": "\u001b[38;2;47;208;247m│ OS\t",
            "format": "{3} {12}"
        },
        {
            "type": "kernel",
            "key": "\u001b[38;2;43;212;239m│ Kernel"
        },
        {
            "type": "uptime",
            "key": "\u001b[38;2;39;217;230m│ Uptime"
        },
        {
            "type": "packages",
            "key": "\u001b[38;2;35;221;222m│ Packages"
        },
        {
            "type": "shell",
            "key": "\u001b[38;2;31;225;214m│ Shell"
        },
        {
            "type": "display",
            "key": "\u001b[38;2;26;229;205m│ Resolution",
            "compactType": "original"
        },
        {
            "type": "terminal",
            "key": "\u001b[38;2;22;233;197m│ Terminal"
        },
        {
            "type": "cpu",
            "key": "\u001b[38;2;14;241;183m│ CPU\t"
        },
        {
            "type": "gpu",
            "key": "\u001b[38;2;17;238;189m│ GPU\t"
        },
        {
            "type": "memory",
            "key": "\u001b[38;2;9;247;172m│ Memory"
        },
        {
            "type": "disk",
            "key": "\u001b[38;2;4;251;162m│ Disk "
        },
        {
            "type": "custom", // InformationEnd
            "format": "\u001b[38;2;0;255;153m└────────────────────────────────────────────────────┘"
        },
        "break",
        {
            "type": "custom", // The Balls
            "format": "\t\u001b[1;30m  \u001b[1;31m  \u001b[1;32m  \u001b[1;33m  \u001b[1;34m  \u001b[1;35m  \u001b[1;36m  \u001b[1;37m "
        },
        {
            "type": "custom", // The Balls Harden
            "format": "\t\u001b[1;90m  \u001b[1;91m  \u001b[1;92m  \u001b[1;93m  \u001b[1;94m  \u001b[1;95m  \u001b[1;96m  \u001b[1;97m "
        }
    ]
}
EOF

echo "Installing Homebrew..."
curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
