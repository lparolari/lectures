# Lecures

A collection of lectures for high-school classes. Code snippets are
mainly in C++, Python or TypeScript.

> If you arrived here, you may also be interested in
> [High Shool Assignments](https://github.com/lparolari/high-school-assignments),
> **a (relative large) collection of exercises for high-school classes
> in computer science**.

## Examples

See some of my lectures for high-school classes:

- [polymorphism in C++](src/polymorphism/polymorphysm.md)
- [recursive functions](src/recursive-functions/recursive-functions.md)
- [lambda functions](src/lambda/lambda.md)
- [computing pi approximation with Euclid's algorithm](src/pi-approx/pi-approx.md)]
- [computability](src/computability/computability.md)
- [formal languages](src/formal-languages/formal-languages.md)
- [Turing machine](src/turing-machine/turing-machine.md)

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

## Related projects

- [High Shool Assignments](https://github.com/lparolari/high-school-assignments),
  a repository with a (relative large) collection of exercises for
  high-school classes in computer science.

- [Computational Thinking in High-School](https://github.com/lparolari/computational-thinking-in-high-school),
  my paper (+ presentation) on computational thinking in high-school
  for the exam "advanced topics on computer science" at University of
  Pauda, Italy.

## Author

Luca Parolari

- Email: [luca.parolari23@gmail.com](mailto:luca.parolari23@gmail.com)
- GitHub: [@lparolari](https://github.com/lparolari)
- Telegram: [@lparolari](https://t.me/lparolari)

## License

MIT
