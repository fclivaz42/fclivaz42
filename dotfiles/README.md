# THE DOTFILES.

I'm gonna keep this one brief:

`bin/` hosts scripts that are stored in my path.

`config/` hosts the configuration I share between my devices. Files prefixed with _ (except Hypr, which uses __ instead) are copied while everything else is symlinked to the cloned repo. This allows me to keep everything in sync.

`home/` hosts some dotfiles that are in the home directory. ALL of those are symlinked.

`plumberd/` is a project i am [currently working on](https://github.com/fclivaz42/plumberd). It has been separated because it is too big on its own to be in my dotfiles.

`zshrc.d/` hosts all of the zsh aliases, exports, plugin sourcing, configs and whatnot.


`Makefile` is what tiews it all together: running `make install` will trigger an installation for a 'supported OS' I have there. It is broken down in `core`, `clangd`, `graphical` which install different reusable parts. `make userjs` will plant a custom user.js file in every firefox profile (or any of its forks).
`folder.sh` and `helper.sh` help `Makefile` do its job. I decided to break them in their own files because it was easier.

`mtab` hosts my [mtab](https://github.com/maxhu08/mtab) config. Who wouldve thought?
`user.js` is the custom user.js i use across all of my firefox (and its forks) profiles.

voila. no fork bomb or other interesting things besides that.
