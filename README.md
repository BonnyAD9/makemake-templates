# makemake-templates
Collection of useful templates for makemake.

Most of these are only supported on posix systems.

The repository is split into folders based on language for which the template is.

## How to install all the templates

#### windows
On windows you need to install all the templates yourself. For example if you want to istall the `vscm` template
and you are in the root of this repository you can run
```shell
makemake -cf vscm C/vscm
```

#### linux
On linux (/ posix complient systems) you can use the script `install-all` to install all the templates at once:
```shell
./install-all
```
by default the script doesn't rewrite any existing templates. You can change that by running:
```
./install-all yes
```
if you want to owerwite only some templates run:
```
./install-all ask
```
this will ask you for every template that would be overwritten
