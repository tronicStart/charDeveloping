#ifndef COMANDS_H
#define COMANDS_H

#include <stdio.h>
#include <tchar.h>

typedef char Public;
typedef char String[500];

/*Lista de comandos de la aplicación: todos se escriben en el input 1*/
Public bye[] = "exit.program";                  //comando para salir
Public screen[] = "clear.screen";               //comando para limpiar la pantalla -> la de la terminal o consola
Public view[] = "view.texture";                 //comando para ver una texture
Public pplayer[] = "player";                    //comando sin uso
Public loadScene[] = "read.scene";              //comando para leer una esena
Public scenesCreator[] = "open.creator.scenes"; //comando para abrir el creador de scenas
Public crearTexture[] = "create.texture";
Public crearFunction[] = "create.fuction";
Public crearObject[] = "create.object";
Public crearNewObject[] = "create.Object";
Public crearNewScene[] = "create.scene.openCreatorEditCMD";
Public crearEditorCPNG[] = "open.editorCPNG.create.cpng";
Public crearCPNG[] = "create.file.cpng";

//palabras reservadas del lenguaje C
const TCHAR *palabrasReservadasC[] = {
    _T("auto"), _T("break"), _T("case"), _T("char"), _T("const"),
    _T("continue"), _T("default"), _T("do"), _T("double"), _T("else"),
    _T("enum"), _T("extern"), _T("float"), _T("for"), _T("goto"),
    _T("if"), _T("int"), _T("long"), _T("register"), _T("return"),
    _T("short"), _T("signed"), _T("sizeof"), _T("static"), _T("struct"),
    _T("switch"), _T("typedef"), _T("union"), _T("unsigned"), _T("void"),
    _T("volatile"), _T("while"), _T("cpng"), _T("texture"), _T("String"), _T("f"),
    _T("function"), _T("Func"), _T("Override"), _T("Scene"), _T("limit"), _T("asset"), _T("Object")};
//palabras reservadas del lenguaje ruby
const TCHAR *palabrasReservadasRuby[] = {
    _T("alias"), _T("break"), _T("case"), _T("when"), _T("and"),
    _T("continue"), _T("default"), _T("do"), _T("class"), _T("def"),
    _T("defined?"), _T("elsif"), _T("end"), _T("for"), _T("ensure"),
    _T("if"), _T("true"), _T("false"), _T("in"), _T("module"),
    _T("next"), _T("nil"), _T("not"), _T("or"), _T("redo"),
    _T("switch"), _T("rescue"), _T("retry"), _T("self"), _T("super"),
    _T("then"), _T("undef"), _T("unless"), _T("until"), _T("yield"), _T("_FILE_"),
    _T("_LINE_")};

#endif
