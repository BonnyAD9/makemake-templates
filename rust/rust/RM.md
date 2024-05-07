# ${pname}
${lib
? '<!--
[![crates.io][version-badge]][crate]
[![downloads][downloads-badge]][releases]
-->'
: '<!-- [![version][version-badge]][aur] -->'
}

TODO: brief description

## Usage
TODO: brief example
${ lib ? '
For more info see [docs][docs].
' : }
## How to get it
${lib
? '<!-- It is available on [crates.io][crate]. -->'
: '<!--
- From the [AUR][aur].
- Or install with this long command (works only on linux):
```sh
wget -nv -O - https://raw.githubusercontent.com/' author_github '/' pname '/master/' pname 'up.sh | sh && sudo cp /tmp/' pname '/target/release/' pname ' /usr/bin/' pname '
```
The second part of the comand uses sudo to copy the files.
-->'
}
TODO: how to get it

## Links
- **Author**: [${author_nick ?? 'author'}][author]
- **GitHub repository**: [${author_github ?? 'author'}/${pname}][repo]
${lib
? '<!-- - **Package**: [crates.io][crate] -->'
: '<!-- - **Package**: [AUR][aur] -->'
}
- **My website**: [${author_web_show}][my-web]

[author]: https://github.com/${author_github}
[repo]: https://github.com/${author_github}/${pname}
${lib
? '[crate]: https://crates.io/crates/' pname '
[version-badge]: https://img.shields.io/crates/v/' pname '
[docs]: https://docs.rs/' pname '/latest/' pname
: '[aur]: https://aur.archlinux.org/packages/' pname '
[version-badge]: https://img.shields.io/aur/version/' pname
}
[my-web]: ${author_web}
[releases]: https://github.com/${author_github}/${pname}/releases
