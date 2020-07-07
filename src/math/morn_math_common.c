/*
Copyright (C) 2019-2020 JingWeiZhangHuai <jingweizhanghuai@163.com>
Licensed under the Apache License, Version 2.0; you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "morn_math.h"

float g_sin_caculate_LUT[901]= {
0.000000000000000f,0.001745328365898f,0.003490651415224f,0.005235963831420f,0.006981260297962f,0.008726535498374f,0.010471784116246f,0.012217000835247f,0.013962180339145f,0.015707317311821f, 
0.017452406437284f,0.019197442399690f,0.020942419883357f,0.022687333572781f,0.024432178152653f,0.026176948307873f,0.027921638723569f,0.029666244085111f,0.031410759078128f,0.033155178388526f, 
0.034899496702501f,0.036643708706556f,0.038387809087520f,0.040131792532560f,0.041875653729200f,0.043619387365336f,0.045362988129254f,0.047106450709643f,0.048849769795613f,0.050592940076713f, 
0.052335956242944f,0.054078812984775f,0.055821504993164f,0.057564026959567f,0.059306373575962f,0.061048539534857f,0.062790519529313f,0.064532308252958f,0.066273900400000f,0.068015290665248f, 
0.069756473744125f,0.071497444332686f,0.073238197127632f,0.074978726826328f,0.076719028126819f,0.078459095727845f,0.080198924328859f,0.081938508630041f,0.083677843332316f,0.085416923137368f, 
0.087155742747658f,0.088894296866442f,0.090632580197780f,0.092370587446562f,0.094108313318514f,0.095845752520224f,0.097582899759150f,0.099319749743639f,0.101056297182946f,0.102792536787247f, 
0.104528463267653f,0.106264071336233f,0.107999355706023f,0.109734311091045f,0.111468932206325f,0.113203213767907f,0.114937150492867f,0.116670737099333f,0.118403968306501f,0.120136838834647f, 
0.121869343405147f,0.123601476740493f,0.125333233564304f,0.127064608601350f,0.128795596577563f,0.130526192220052f,0.132256390257122f,0.133986185418292f,0.135715572434304f,0.137444546037147f, 
0.139173100960065f,0.140901231937583f,0.142628933705512f,0.144356201000973f,0.146083028562412f,0.147809411129611f,0.149535343443710f,0.151260820247219f,0.152985836284038f,0.154710386299468f, 
0.156434465040231f,0.158158067254484f,0.159881187691835f,0.161603821103361f,0.163325962241622f,0.165047605860678f,0.166768746716102f,0.168489379565003f,0.170209499166033f,0.171929100279410f, 
0.173648177666930f,0.175366726091987f,0.177084740319583f,0.178802215116350f,0.180519145250560f,0.182235525492147f,0.183951350612720f,0.185666615385577f,0.187381314585725f,0.189095442989891f, 
0.190808995376545f,0.192521966525907f,0.194234351219972f,0.195946144242518f,0.197657340379126f,0.199367934417197f,0.201077921145965f,0.202787295356512f,0.204496051841790f,0.206204185396630f, 
0.207911690817759f,0.209618562903822f,0.211324796455389f,0.213030386274977f,0.214735327167063f,0.216439613938103f,0.218143241396543f,0.219846204352837f,0.221548497619467f,0.223250116010951f, 
0.224951054343865f,0.226651307436855f,0.228350870110656f,0.230049737188104f,0.231747903494157f,0.233445363855905f,0.235142113102590f,0.236838146065619f,0.238533457578581f,0.240228042477264f, 
0.241921895599668f,0.243615011786023f,0.245307385878803f,0.246999012722743f,0.248689887164855f,0.250380004054441f,0.252069358243114f,0.253757944584806f,0.255445757935790f,0.257132793154696f, 
0.258819045102521f,0.260504508642648f,0.262189178640865f,0.263873049965373f,0.265556117486809f,0.267238376078257f,0.268919820615266f,0.270600445975864f,0.272280247040574f,0.273959218692432f, 
0.275637355816999f,0.277314653302378f,0.278991106039229f,0.280666708920788f,0.282341456842876f,0.284015344703923f,0.285688367404974f,0.287360519849712f,0.289031796944472f,0.290702193598252f, 
0.292371704722737f,0.294040325232304f,0.295708050044047f,0.297374874077786f,0.299040792256087f,0.300705799504273f,0.302369890750445f,0.304033060925490f,0.305695304963106f,0.307356617799807f, 
0.309016994374947f,0.310676429630732f,0.312334918512233f,0.313992455967405f,0.315649036947102f,0.317304656405092f,0.318959309298070f,0.320612990585676f,0.322265695230511f,0.323917418198149f, 
0.325568154457157f,0.327217898979104f,0.328866646738583f,0.330514392713223f,0.332161131883703f,0.333806859233771f,0.335451569750255f,0.337095258423082f,0.338737920245291f,0.340379550213050f, 
0.342020143325669f,0.343659694585616f,0.345298198998535f,0.346935651573256f,0.348572047321815f,0.350207381259467f,0.351841648404702f,0.353474843779257f,0.355106962408137f,0.356737999319625f, 
0.358367949545300f,0.359996808120051f,0.361624570082092f,0.363251230472978f,0.364876784337620f,0.366501226724297f,0.368124552684678f,0.369746757273829f,0.371367835550235f,0.372987782575809f, 
0.374606593415912f,0.376224263139366f,0.377840786818467f,0.379456159529005f,0.381070376350274f,0.382683432365090f,0.384295322659804f,0.385906042324319f,0.387515586452103f,0.389123950140206f, 
0.390731128489274f,0.392337116603561f,0.393941909590951f,0.395545502562965f,0.397147890634781f,0.398749068925246f,0.400349032556895f,0.401947776655960f,0.403545296352390f,0.405141586779863f, 
0.406736643075800f,0.408330460381385f,0.409923033841573f,0.411514358605109f,0.413104429824542f,0.414693242656239f,0.416280792260401f,0.417867073801077f,0.419452082446177f,0.421035813367491f, 
0.422618261740699f,0.424199422745390f,0.425779291565073f,0.427357863387192f,0.428935133403146f,0.430511096808295f,0.432085748801982f,0.433659084587544f,0.435231099372328f,0.436801788367702f, 
0.438371146789077f,0.439939169855915f,0.441505852791745f,0.443071190824180f,0.444635179184927f,0.446197813109809f,0.447759087838770f,0.449318998615897f,0.450877540689431f,0.452434709311783f, 
0.453990499739547f,0.455544907233516f,0.457097927058694f,0.458649554484315f,0.460199784783852f,0.461748613235034f,0.463296035119862f,0.464842045724620f,0.466386640339891f,0.467929814260573f, 
0.469471562785891f,0.471011881219410f,0.472550764869054f,0.474088209047116f,0.475624209070275f,0.477158760259608f,0.478691857940607f,0.480223497443189f,0.481753674101715f,0.483282383255002f, 
0.484809620246337f,0.486335380423491f,0.487859659138733f,0.489382451748846f,0.490903753615141f,0.492423560103467f,0.493941866584231f,0.495458668432407f,0.496973961027555f,0.498487739753830f, 
0.500000000000000f,0.501510737159457f,0.503019946630235f,0.504527623815019f,0.506033764121164f,0.507538362960704f,0.509041415750371f,0.510542917911606f,0.512042864870572f,0.513541252058170f, 
0.515038074910054f,0.516533328866642f,0.518027009373130f,0.519519111879509f,0.521009631840576f,0.522498564715949f,0.523985905970079f,0.525471651072268f,0.526955795496678f,0.528438334722347f, 
0.529919264233205f,0.531398579518083f,0.532876276070730f,0.534352349389826f,0.535826794978997f,0.537299608346824f,0.538770785006863f,0.540240320477655f,0.541708210282740f,0.543174449950671f, 
0.544639035015027f,0.546101961014429f,0.547563223492550f,0.549022817998132f,0.550480740084995f,0.551936985312058f,0.553391549243344f,0.554844427447999f,0.556295615500305f,0.557745108979690f, 
0.559192903470747f,0.560638994563242f,0.562083377852131f,0.563526048937571f,0.564967003424938f,0.566406236924833f,0.567843745053101f,0.569279523430844f,0.570713567684432f,0.572145873445516f, 
0.573576436351046f,0.575005252043279f,0.576432316169793f,0.577857624383505f,0.579281172342679f,0.580702955710940f,0.582122970157289f,0.583541211356118f,0.584957674987215f,0.586372356735789f, 
0.587785252292473f,0.589196357353342f,0.590605667619925f,0.592013178799219f,0.593418886603701f,0.594822786751341f,0.596224874965616f,0.597625146975521f,0.599023598515586f,0.600420225325884f, 
0.601815023152048f,0.603207987745283f,0.604599114862375f,0.605988400265711f,0.607375839723287f,0.608761429008721f,0.610145163901268f,0.611527040185831f,0.612907053652976f,0.614285200098943f, 
0.615661475325658f,0.617035875140749f,0.618408395357554f,0.619779031795140f,0.621147780278310f,0.622514636637620f,0.623879596709386f,0.625242656335705f,0.626603811364460f,0.627963057649338f, 
0.629320391049837f,0.630675807431286f,0.632029302664851f,0.633380872627550f,0.634730513202268f,0.636078220277764f,0.637423989748690f,0.638767817515598f,0.640109699484955f,0.641449631569158f, 
0.642787609686539f,0.644123629761386f,0.645457687723951f,0.646789779510460f,0.648119901063131f,0.649448048330184f,0.650774217265851f,0.652098403830392f,0.653420603990105f,0.654740813717340f, 
0.656059028990507f,0.657375245794096f,0.658689460118681f,0.660001667960937f,0.661311865323652f,0.662620048215738f,0.663926212652242f,0.665230354654361f,0.666532470249453f,0.667832555471047f, 
0.669130606358858f,0.670426618958799f,0.671720589322990f,0.673012513509773f,0.674302387583723f,0.675590207615660f,0.676875969682661f,0.678159669868071f,0.679441304261516f,0.680720868958918f, 
0.681998360062498f,0.683273773680799f,0.684547105928689f,0.685818352927376f,0.687087510804423f,0.688354575693754f,0.689619543735670f,0.690882411076858f,0.692143173870407f,0.693401828275813f, 
0.694658370458997f,0.695912796592314f,0.697165102854565f,0.698415285431006f,0.699663340513365f,0.700909264299851f,0.702153052995162f,0.703394702810504f,0.704634209963595f,0.705871570678681f, 
0.707106781186547f,0.708339837724529f,0.709570736536521f,0.710799473872992f,0.712026045990996f,0.713250449154182f,0.714472679632803f,0.715692733703736f,0.716910607650483f,0.718126297763189f, 
0.719339800338651f,0.720551111680330f,0.721760228098362f,0.722967145909568f,0.724171861437467f,0.725374371012288f,0.726574670970976f,0.727772757657211f,0.728968627421411f,0.730162276620752f, 
0.731353701619170f,0.732542898787379f,0.733729864502876f,0.734914595149960f,0.736097087119734f,0.737277336810124f,0.738455340625884f,0.739631094978610f,0.740804596286750f,0.741975840975616f, 
0.743144825477394f,0.744311546231154f,0.745475999682862f,0.746638182285391f,0.747798090498532f,0.748955720789002f,0.750111069630460f,0.751264133503511f,0.752414908895724f,0.753563392301638f, 
0.754709580222772f,0.755853469167640f,0.756995055651757f,0.758134336197652f,0.759271307334881f,0.760405965600031f,0.761538307536737f,0.762668329695688f,0.763796028634642f,0.764921400918432f, 
0.766044443118978f,0.767165151815300f,0.768283523593523f,0.769399555046895f,0.770513242775789f,0.771624583387720f,0.772733573497351f,0.773840209726506f,0.774944488704180f,0.776046407066546f, 
0.777145961456971f,0.778243148526021f,0.779337964931474f,0.780430407338330f,0.781520472418819f,0.782608156852414f,0.783693457325840f,0.784776370533083f,0.785856893175402f,0.786935021961337f, 
0.788010753606722f,0.789084084834691f,0.790155012375690f,0.791223532967490f,0.792289643355191f,0.793353340291235f,0.794414620535418f,0.795473480854896f,0.796529918024196f,0.797583928825228f, 
0.798635510047293f,0.799684658487090f,0.800731370948733f,0.801775644243754f,0.802817475191114f,0.803856860617217f,0.804893797355914f,0.805928282248516f,0.806960312143802f,0.807989883898031f, 
0.809016994374947f,0.810041640445796f,0.811063818989327f,0.812083526891806f,0.813100761047028f,0.814115518356319f,0.815127795728554f,0.816137590080160f,0.817144898335128f,0.818149717425023f, 
0.819152044288992f,0.820151875873772f,0.821149209133704f,0.822144041030737f,0.823136368534442f,0.824126188622016f,0.825113498278295f,0.826098294495764f,0.827080574274562f,0.828060334622494f, 
0.829037572555042f,0.830012285095368f,0.830984469274328f,0.831954122130482f,0.832921240710100f,0.833885822067168f,0.834847863263407f,0.835807361368270f,0.836764313458962f,0.837718716620439f, 
0.838670567945424f,0.839619864534413f,0.840566603495684f,0.841510781945306f,0.842452397007148f,0.843391445812886f,0.844327925502015f,0.845261833221856f,0.846193166127564f,0.847121921382137f, 
0.848048096156426f,0.848971687629141f,0.849892692986864f,0.850811109424051f,0.851726934143048f,0.852640164354092f,0.853550797275327f,0.854458830132807f,0.855364260160507f,0.856267084600328f, 
0.857167300702112f,0.858064905723645f,0.858959896930664f,0.859852271596873f,0.860742027003944f,0.861629160441526f,0.862513669207257f,0.863395550606772f,0.864274801953705f,0.865151420569705f, 
0.866025403784439f,0.866896748935603f,0.867765453368929f,0.868631514438191f,0.869494929505219f,0.870355695939900f,0.871213811120189f,0.872069272432121f,0.872922077269810f,0.873772223035465f, 
0.874619707139396f,0.875464527000018f,0.876306680043864f,0.877146163705589f,0.877982975427981f,0.878817112661965f,0.879648572866617f,0.880477353509162f,0.881303452064992f,0.882126866017668f, 
0.882947592858927f,0.883765630088693f,0.884580975215084f,0.885393625754416f,0.886203579231215f,0.887010833178222f,0.887815385136401f,0.888617232654949f,0.889416373291297f,0.890212804611126f, 
0.891006524188368f,0.891797529605214f,0.892585818452125f,0.893371388327838f,0.894154236839368f,0.894934361602025f,0.895711760239413f,0.896486430383441f,0.897258369674328f,0.898027575760616f, 
0.898794046299167f,0.899557778955180f,0.900318771402194f,0.901077021322092f,0.901832526405114f,0.902585284349861f,0.903335292863301f,0.904082549660778f,0.904827052466019f,0.905568799011140f, 
0.906307787036650f,0.907044014291465f,0.907777478532909f,0.908508177526722f,0.909236109047069f,0.909961270876543f,0.910683660806177f,0.911403276635445f,0.912120116172273f,0.912834177233043f, 
0.913545457642601f,0.914253955234264f,0.914959667849825f,0.915662593339561f,0.916362729562240f,0.917060074385124f,0.917754625683981f,0.918446381343087f,0.919135339255234f,0.919821497321738f, 
0.920504853452440f,0.921185405565721f,0.921863151588501f,0.922538089456246f,0.923210217112981f,0.923879532511287f,0.924546033612313f,0.925209718385782f,0.925870584809995f,0.926528630871837f, 
0.927183854566787f,0.927836253898920f,0.928485826880914f,0.929132571534056f,0.929776485888251f,0.930417567982025f,0.931055815862528f,0.931691227585549f,0.932323801215512f,0.932953534825489f, 
0.933580426497202f,0.934204474321029f,0.934825676396014f,0.935444030829867f,0.936059535738973f,0.936672189248398f,0.937281989491891f,0.937888934611898f,0.938493022759556f,0.939094252094709f, 
0.939692620785908f,0.940288127010419f,0.940880768954225f,0.941470544812038f,0.942057452787297f,0.942641491092178f,0.943222657947601f,0.943800951583229f,0.944376370237481f,0.944948912157531f, 
0.945518575599317f,0.946085358827545f,0.946649260115696f,0.947210277746029f,0.947768410009586f,0.948323655206199f,0.948876011644497f,0.949425477641904f,0.949972051524652f,0.950515731627784f, 
0.951056516295154f,0.951594403879438f,0.952129392742139f,0.952661481253586f,0.953190667792947f,0.953716950748227f,0.954240328516277f,0.954760799502797f,0.955278362122344f,0.955793014798330f, 
0.956304755963035f,0.956813584057607f,0.957319497532067f,0.957822494845315f,0.958322574465133f,0.958819734868193f,0.959313974540057f,0.959805291975187f,0.960293685676943f,0.960779154157594f, 
0.961261695938319f,0.961741309549211f,0.962217993529285f,0.962691746426479f,0.963162566797658f,0.963630453208623f,0.964095404234110f,0.964557418457798f,0.965016494472311f,0.965472630879225f, 
0.965925826289068f,0.966376079321329f,0.966823388604459f,0.967267752775877f,0.967709170481971f,0.968147640378108f,0.968583161128631f,0.969015731406870f,0.969445349895139f,0.969872015284747f, 
0.970295726275996f,0.970716481578191f,0.971134279909636f,0.971549119997646f,0.971961000578546f,0.972369920397677f,0.972775878209396f,0.973178872777088f,0.973578902873160f,0.973975967279052f, 
0.974370064785235f,0.974761194191222f,0.975149354305563f,0.975534543945857f,0.975916761938747f,0.976296007119933f,0.976672278334168f,0.977045574435264f,0.977415894286096f,0.977783236758606f, 
0.978147600733806f,0.978508985101778f,0.978867388761685f,0.979222810621766f,0.979575249599344f,0.979924704620830f,0.980271174621722f,0.980614658546613f,0.980955155349192f,0.981292663992245f, 
0.981627183447664f,0.981958712696444f,0.982287250728689f,0.982612796543615f,0.982935349149554f,0.983254907563955f,0.983571470813386f,0.983885037933542f,0.984195607969242f,0.984503179974437f, 
0.984807753012208f,0.985109326154774f,0.985407898483490f,0.985703469088854f,0.985996037070505f,0.986285601537231f,0.986572161606969f,0.986855716406807f,0.987136265072988f,0.987413806750911f, 
0.987688340595138f,0.987959865769389f,0.988228381446553f,0.988493886808684f,0.988756381047006f,0.989015863361917f,0.989272332962988f,0.989525789068969f,0.989776230907789f,0.990023657716558f, 
0.990268068741570f,0.990509463238309f,0.990747840471444f,0.990983199714836f,0.991215540251542f,0.991444861373810f,0.991671162383090f,0.991894442590030f,0.992114701314478f,0.992331937885489f, 
0.992546151641322f,0.992757341929446f,0.992965508106537f,0.993170649538486f,0.993372765600396f,0.993571855676587f,0.993767919160596f,0.993960955455180f,0.994150963972315f,0.994337944133205f, 
0.994521895368273f,0.994702817117174f,0.994880708828788f,0.995055569961226f,0.995227399981831f,0.995396198367179f,0.995561964603080f,0.995724698184582f,0.995884398615970f,0.996041065410770f, 
0.996194698091746f,0.996345296190906f,0.996492859249504f,0.996637386818037f,0.996778878456247f,0.996917333733128f,0.997052752226920f,0.997185133525116f,0.997314477224458f,0.997440782930944f, 
0.997564050259824f,0.997684278835605f,0.997801468292050f,0.997915618272179f,0.998026728428272f,0.998134798421867f,0.998239827923765f,0.998341816614028f,0.998440764181981f,0.998536670326212f, 
0.998629534754574f,0.998719357184186f,0.998806137341434f,0.998889874961970f,0.998970569790715f,0.999048221581858f,0.999122830098858f,0.999194395114446f,0.999262916410621f,0.999328393778656f, 
0.999390827019096f,0.999450215941757f,0.999506560365732f,0.999559860119384f,0.999610115040354f,0.999657324975557f,0.999701489781183f,0.999742609322698f,0.999780683474845f,0.999815712121644f, 
0.999847695156391f,0.999876632481661f,0.999902524009304f,0.999925369660452f,0.999945169365512f,0.999961923064171f,0.999975630705395f,0.999986292247427f,0.999993907657790f,0.999998476913288f, 
1.0f};

float mSin(float a)
{
    int x;
    if(a>0.0f)
    {
        x = (int)(a*10.0f+0.5f);
        x = x%3600;
        if((x>=0)&&(x<900))
            return g_sin_caculate_LUT[x];
        else if(x<1800)
            return g_sin_caculate_LUT[1800-x];
        else if(x<2700)
            return (0.0f-g_sin_caculate_LUT[x-1800]);
        else
            return (0.0f-g_sin_caculate_LUT[3600-x]);
    }
    else
    {
        x = (int)((0.0f-a)*10.0f+0.5f);
        x = x%3600;
        if((x>=0)&&(x<900))
            return (0.0f-g_sin_caculate_LUT[x]);
        else if(x<1800)
            return (0.0f-g_sin_caculate_LUT[1800-x]);
        else if(x<2700)
            return g_sin_caculate_LUT[x-1800];
        else
            return g_sin_caculate_LUT[3600-x];
    }
}

float mCos(float a)
{
    int x;
    x = (int)(ABS(a)*10.0f+0.5f);
    x = x%3600;
    
    if((x>=0)&&(x<900))
        return g_sin_caculate_LUT[900-x];
    else if(x<1800)
        return (0.0f-g_sin_caculate_LUT[x-900]);
    else if(x<2700)
        return (0.0f-g_sin_caculate_LUT[2700-x]);
    else
        return g_sin_caculate_LUT[x-2700];
}

// float mTan(float a) {return mSin(a)/mCos(a);}
// float mCot(float a) {return mCos(a)/m

void mMean(float *in,int num,float *sum,float *mean)
{
    float m;
    int i;
    mException((INVALID_POINTER(in))||(num <= 0),EXIT,"invalid input");
    
    m = 0.0f;
    for(i=0;i<num;i++)
        m = m + in[i];
    
    if(!INVALID_POINTER(sum)) *sum = m;
    if(!INVALID_POINTER(mean)) *mean = m/((float)num);
}

void mVariance(float *in,int num,float *mean,float *variance)
{
    float sum=0.0f;
    float var=0.0f;
    int i;
    mException((INVALID_POINTER(in))||(num <= 0)||(INVALID_POINTER(variance)),EXIT,"invalid input");
    
    for(i=0;i<num;i++)
    {
        sum = sum + in[i];
        var = var + in[i]*in[i];
    }
    sum = sum/((float)num);
    if(!INVALID_POINTER(mean)) *mean = sum;
    *variance = var/((float)num) - (sum*sum);
}

void mCovariance(float *in1,float *in2,int num,float *mean1,float *mean2,float *covariance)
{
    float sum1 = 0.0f;
    float sum2 = 0.0f;
    float cosum = 0.0f;
    int i;
    
    mException((INVALID_POINTER(in1))||(INVALID_POINTER(in2))||(num <= 0)||(INVALID_POINTER(covariance)),EXIT,"invalid input");
    for(i=0;i<num;i++)
    {
        sum1 =sum1 + in1[i];
        sum2 =sum2 + in2[i];
        cosum = cosum +in1[i] * in2[i];
    }
    sum1 = sum1/((float)num);
    sum2 = sum2/((float)num);
    if(!INVALID_POINTER(mean1)) *mean1 = sum1;
    if(!INVALID_POINTER(mean2)) *mean2 = sum1;
    *covariance = cosum/((float)num) - sum1*sum2;
}

#define MID_INDEX(I1,I2,I3) (((value[I1]>value[I2])==(value[I2]>=value[I3]))?I2:(((value[I1]>value[I2])==(value[I3]>=value[I1]))?I1:I3))
void mApproxMidValue(float *value,int num,float *mid,int *idx)
{
    int n;for(n=9;n<num/4;n=n*3);
    int *index = (int *)mMalloc(sizeof(int)*n);
    float step = (float)num/(float)n;for(int i=0;i<n;i++) index[i] = i*step;
    for(;n>1;n=n/3)
    {
        for(int i=0,j=0;i<n;i+=3,j+=1)
        {
            printf("%f,%f,%f",value[index[i]],value[index[i+1]],value[index[i+2]]);
            index[j] = MID_INDEX(index[i],index[i+1],index[i+2]);
            printf("-->%f\n",value[index[j]]);
        }
        printf("\n");
    }
    
    if(mid != NULL) *mid = value[index[0]];
    if(idx != NULL) *idx = index[0];
    
    mFree(index);
}

double mSigmoid(float x)
{
    return (1.0/(1.0+exp((double)(0.0f-x))));
}

unsigned int mHash(const char *in,int size)
{
    unsigned int out;
    int i;
    
    mException(INVALID_POINTER(in),EXIT,"invalid input");
    
    out = 0x811C9DC5;
    for(i=0;(size<=0)?(in[i]!='\0'):(i<=size);i++)
    {
        out = out^(unsigned int)in[i];
        out = (out<<24)+(out<<8)+(out<<6)+(out<<4)+(out<<3)+(out<<2)+out;
    }
    
    return out;
}
