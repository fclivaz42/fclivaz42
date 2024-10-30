# HOMEBREW CONFIG

# Add brew to path
export PATH=$HOME/.brew/bin:$PATH

# Set Homebrew temporary folders
export HOMEBREW_CACHE=/tmp/$USER/Homebrew/Caches
export HOMEBREW_TEMP=/tmp/$USER/Homebrew/Temp

mkdir -p $HOMEBREW_CACHE
mkdir -p $HOMEBREW_TEMP
