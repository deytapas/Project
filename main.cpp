#include <iostream>

using namespace std;
class Item
{
        string product_name;
        int unit_price;
        int gst;
        int quentity;
        float discount=0;
        float GstCount=0;
        float totalPrice=0;
    public:
        Item(string product_name,int unit_price,int gst,int quentity)
        {
            this->product_name=product_name;
            this->unit_price=unit_price;
            this->gst=gst;
            this->quentity=quentity;
        }
        float calculate()
        {
            float PriceOfQuentity=0;
           float totalPriceWithGst=0;
          if(unit_price>=500)
          {
             PriceOfQuentity=unit_price*quentity;

             discount=(5*PriceOfQuentity)/100;
             totalPrice=PriceOfQuentity-discount;
              totalPriceWithGst=totalPrice;
              if(gst>0){
             for(int i=0;i<quentity;i++)
             {
                 totalPriceWithGst=totalPriceWithGst+((totalPrice*gst)/100);
             }
              }
          }
          else
          {
             PriceOfQuentity=unit_price*quentity;
             totalPriceWithGst=PriceOfQuentity;
             totalPrice=unit_price;
             if(gst>0){
             for(int i=0;i<quentity;i++)
             {
                 totalPriceWithGst=totalPriceWithGst+((totalPrice*gst)/100);
             }
             }

          }
          return totalPriceWithGst;
        }
};

int main()
{
    struct {
        string product_name;
        int unit_price;
        int gst;
        int quentity;
    } product1,product2,product3,product4;
    product1.product_name="Leather wallet";
    product1.unit_price=1100;
    product1.gst=18;
    product1.quentity=1;


    product2.product_name="Umbrella";
    product2.unit_price=900;
    product2.gst=12;
    product2.quentity=2;


    product3.product_name="Cigarette";
    product3.unit_price=200;
    product3.gst=28;
    product3.quentity=3;


    product4.product_name="Honey";
    product4.unit_price=100;
    product4.gst=0;
    product4.quentity=4;
    //cout<<product1.product_name;
    Item wallet(product1.product_name,product1.unit_price,product1.gst,product1.quentity);
    float costofwallet=wallet.calculate();
    Item Umbrella(product2.product_name,product2.unit_price,product2.gst,product2.quentity);
    float costofUmbrella=Umbrella.calculate();
    Item Cigarette(product3.product_name,product3.unit_price,product3.gst,product3.quentity);
    float costofCigarette=Cigarette.calculate();

    Item Honey(product4.product_name,product4.unit_price,product4.gst,product4.quentity);
    float costofHoney=Honey.calculate();
    float total=costofwallet+costofUmbrella+costofCigarette+costofHoney;
    cout<<"the total amount to be paid to the shop-keeper is: "<<total;
    return 0;
}
