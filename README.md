# Lecures

A collection of lectures for high-school classes. Code snippets are
mainly in C++, Python or TypeScript.

## Usage

### Create a new lecture

```bash
LECTURE=your-lecture

   mkdir -p src/${LECTURE} \
&& cd src/${LECTURE} \
&& echo "# TODO" > ${LECTURE}.md \
&& ln -s ../../Makefile Makefile
```

### Compile a lecture (PDF output)

```bash
LECTURE=your-lecture
```

```bash
make MAINFILE=${LECTURE} -C src/${LECTURE}
```

## Pandoc

Please note that `.md` source files are written in _Markdown_, but
they may integrate _latex_ syntax which can be compiled to pdf by
Pandoc.

## Author

Luca Parolari

- Email: [luca.parolari23@gmail.com](mailto:luca.parolari23@gmail.com)
- GitHub: [@lparolari](https://github.com/lparolari)
- Telegram: [@lparolari](https://t.me/lparolari)

## License

MIT
