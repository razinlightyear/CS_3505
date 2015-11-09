#-------------------------------------------------
#
# Project created by QtCreator 2015-10-29T09:46:23
#
#-------------------------------------------------

QT += widgets
qtHaveModule(printsupport): QT += printsupport

HEADERS       = mainwindow.h \
                scribblearea.h
SOURCES       = main.cpp \
                mainwindow.cpp \
                scribblearea.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/scribble
INSTALLS += target
