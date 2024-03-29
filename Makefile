MAINFILE?=README
SRC?=`pwd`

PANDOC_ARGS=--rm --volume "${SRC}:/data" --user `id -u`:`id -g`
PANDOC_EXTRA=--variable urlcolor=cyan

# project-level recipe
pdf: ${MAINFILE}.pdf

# main recipe
${MAINFILE}.pdf:
	docker run ${PANDOC_ARGS} pandoc/latex ${MAINFILE}.md -o ${MAINFILE}.pdf ${PANDOC_EXTRA}
# make it a phony target in order to always perform compilation
# even if the file already exists.
.PHONY: ${MAINFILE}.pdf

clean: clear
clear:
	rm -f *.pdf

.PHONY: pdf clean clear
