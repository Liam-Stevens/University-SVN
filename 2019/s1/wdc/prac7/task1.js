/*
Top menu:
{ title:'Home',         url:'/' }
{ title:'About',        url:'/about' }
{ title:'Contact Us',   url:'/contact' }

Stores:
{ name:'Adelaide City',  address:'45 Florabunda Lane, Adelaide, 5000', img:'https://upload.wikimedia.org/wikipedia/commons/thumb/9/99/11_Gloddaeth_Street%2C_Llandudno_shop_front.jpg/320px-11_Gloddaeth_Street%2C_Llandudno_shop_front.jpg' }
{ name:'Steelton South', address:'77 Weigall Avenue, Steelton, 5413',  img:'https://upload.wikimedia.org/wikipedia/commons/4/42/Well-shop-front.jpg' }
{ name:'Milton',         address:'33 McGregor Street, Milton, 5880',   img:'https://upload.wikimedia.org/wikipedia/en/thumb/e/e2/Greggs_store_front.JPG/320px-Greggs_store_front.JPG' }

*/

var ads = [
    { name:'Lemon', url:'https://almostrealthings.com/wp-content/uploads/2015/05/lemon.jpg' },
    { name:'AdMen', url:'https://almostrealthings.com/wp-content/uploads/2015/09/admen.jpg' },
    { name:'Justified Type Corp', url:'https://almostrealthings.com/wp-content/uploads/2015/05/justified-type-corp.jpg' }
];

var vueinst = new Vue({
    el: '#first',
    data: {
        text: 'Pretty good.'
    }
});
