import React from 'react';
import {View, Text, Linking, StyleSheet, Pressable, SafeAreaView, StatusBar, Image} from 'react-native';

const imageProfileGitHub = 'https://avatars.githubusercontent.com/u/91329879?v=4';
const colorGitHub = '#010409';
const colorFontDarkGit = '#C9D1D9';
const urlGitHub ='https://github.com/iarinhasz';
const App = ()=>{ 

    const handlePressGoToGitHub = async()=>{
        const rest = await Linking.canOpenURL(urlGitHub);
        if(rest) await Linking.openURL(urlGitHub);
    }
    return(
        <SafeAreaView style ={style.container}>
            <StatusBar backgroundColor={colorGitHub} barStyle ="ligth-content"/>
            //eu estou criando os estilos e suas funcoes
            <View style={style.content} >
                <Image
                    accessibilityLabel="Iara tirando foto no espelho"
                    style={style.avatar}
                    source ={{uri: imageProfileGitHub}}
                />
                //ainda da p adicionar uma cor dentro desse array
                <Text style = {[style.defaultText, style.name]}> Iara Yasmin</Text>
                <Text style = {[style.defaultText, style.nickname]}> iarinhasz</Text>
                <Text style = {[style.defaultText, style.descricao]}> Developer Front-End</Text>
                <Pressable onPress={handlePressGoToGitHub}>
                    <View style = {style.button}>
                        <Text style = {[style.defaultText, style.textButton]}>
                            Open in GitHub
                        </Text>
                    </View>
                </Pressable>
                
            </View>
        </SafeAreaView>
    );
};

export default App;
const style = StyleSheet.create({
    container: {
        //funciona como se fosse um tipo de coluna
        backgroundColor: 'pink',
        /*o tamanho max eh  ate preencher*/
        flex: 1,
        justifyContent:'center',
        alignItems:'center',
    },
    text:{
        fontSize: 50,
        fontWeight: 'bold',
        color: 'black',
    },
    content:{
        alignItems: 'center',
        padding: 20,
    },
    avatar:{
        height: 200,
        width: 200,
        borderRadius: 100,
        borderColor: 'white',
        borderWidth: 2,
    },
    defaultText:{
        color: 'white',
    },
    name:{
        marginTop: 20,
        fontWeight: 'bold',
        fontSize: 24,
    },
    nickname:{
        fontSize: 18,
        color: colorFontDarkGit,
    },
    descricao:{
        fontWeight: 'bold',
        fontSize: 14,
    },
    button:{
        marginTop: 20,
        backgroundColor: colorFontDarkGit,
        borderRadius: 10,
        padding: 20,
    },
    textButton:{
        fontWeight: 'bold',
        fontSize: 16,
    },
});